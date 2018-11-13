/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmyrzata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:00:14 by bmyrzata          #+#    #+#             */
/*   Updated: 2018/11/12 23:38:12 by bmyrzata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define FLINE_MAX_SIZE 15

typedef struct	s_binfo
{
	unsigned int	lines;
	char			empty;
	char			obstacle;
	char			full;
}				t_binfo;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*get_fline(int fd)
{
	int		i;
	char	c;
	char	*fline;

	fline = malloc(sizeof(char) * FLINE_MAX_SIZE);

	i = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		fline[i] = c;
		i++;
	}
	fline[i] = '\0';

	return (fline);
}

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

t_binfo	get_binfo(char *fline)
{
	int i;
	int count;
	t_binfo binfo;

	binfo.lines = ft_atoi(fline);

	count = 0;
	i = 0;
	while (fline[i] != '\0')
	{
		if (is_num(fline[i]) == 0)
		{	
			if (count < 1)
			{
				binfo.empty = fline[i];
				count++;
			}
			else if (count == 1)
			{
				binfo.obstacle = fline[i];
				count++;
			}
			else if (count > 1)
			{
				binfo.full = fline[i];
				count++;
			}
		}
		i++;
	}
	return (binfo);
}

char	**get_matrix(int fd, int lines)
{
	char **matrix;
	int i;
	int j;
	char c;
	int elem;

	matrix = malloc(sizeof(char*) * (lines + 1));
	
	i = 0;
	elem = 0;
	while (i < lines)
	{
		j = 0;
		if (elem == 0)
			matrix[i] = malloc(sizeof(char) * (20));
		else
			matrix[i] = malloc(sizeof(char) * (elem + 1));
		
		while (read(fd, &c, 1) && c != '\n')
		{
			matrix[i][j] = c;
			j++;
			elem++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}


void	print_board(char **board)
{
	int	i;

	i = 0;
	while (board[i] != 0)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

typedef struct	s_snap
{
	int x;
	int y;
	int swipe;
}				t_snap;

int		find_swipe(char **matrix, char obstacle, int x, int y, int swipe)
{
	int i;
	int j;

	if (matrix[0][x + 1 + swipe] && matrix[y + 1 + swipe])
	{
		i = y;
		while (i < y + 1 + swipe)
		{
			if (matrix[i][x + 1 + swipe] == obstacle)
				return swipe;
			i++;
		}

		j = x;
		while (j < x + 1 + swipe)
		{
			if (matrix[i][j] == obstacle)
				return swipe;
			j++;
		}

		swipe++;
		return (find_swipe(matrix, obstacle, x, y, swipe));
	}
	else if (matrix[y][x] == obstacle)
	{
		return swipe;
	}
	else
	{
		return swipe;
	}
}

char	**solve_matrix(char **matrix, t_binfo binfo)
{
	t_snap			snapshot;
	unsigned int	i;
	int				j;
	int				swipe;
	int				count;

	count = 0;

	// i = 0;
	// j = 5;
	// snapshot.x = j;
	// snapshot.y = i;
	// snapshot.swipe = find_swipe(matrix, binfo.empty, j, i, 0);
	// printf("Swipe: %d\n", snapshot.swipe);

	snapshot.swipe = 0;

	i = 0;
	while (i < binfo.lines)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			snapshot.x = j;
			snapshot.y = i;
			swipe = find_swipe(matrix, binfo.obstacle, j, i, 0);
			if (swipe > snapshot.swipe)
			{
				snapshot.swipe = swipe;
			}
			// snapshot.swipe = find_swipe(matrix, binfo.empty, j, i, 0);
			printf("Swipe: %d\n", swipe);
			count++;
			j++;
		}
		i++;
	}
	printf("Count: %d\n", count);
	return matrix;

}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*fline;
	char	**matrix;
	t_binfo	binfo;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() failed\n");
			return (1);
		}

		fline = get_fline(fd);
		binfo = get_binfo(fline);
        matrix = get_matrix(fd, binfo.lines);
		
		//validate(matrix);
		matrix = solve_matrix(matrix, binfo);

		if (close(fd) < 0)
		{
			ft_putstr("close() failed\n");
			return (1);
		}
	}

	return (0);
}
