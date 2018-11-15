/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmyrzata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:00:14 by bmyrzata          #+#    #+#             */
/*   Updated: 2018/11/14 16:20:36 by bmyrzata         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_realloc(char *str, char c, int width)
{
	char	*temp;

	temp = malloc(sizeof(char) * (width + 1));
	temp = ft_strcpy(temp, str, width - 1);
	temp[width - 1] = c;
	temp[width] = '\0';
	return (temp);
}

char	**get_matrix(int fd, int lines)
{
	char	**matrix;
	int		i;
	int		j;
	char	c;
	int		width;

	matrix = malloc(sizeof(char*) * (lines + 1));
	width = 0;
	matrix[0] = NULL;
	while (read(fd, &c, 1) && c != '\n')
	{
		width++;
		matrix[0] = ft_realloc(matrix[0], c, width);
	}

	i = 1;
	while (i < lines)
	{
		j = 0;
		matrix[i] = malloc(sizeof(char) * (width + 1));
		while (read(fd, &c, 1) && c != '\n')
		{
			matrix[i][j] = c;
			j++;
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

typedef struct	s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}				t_list;

typedef struct	s_snap
{
	int x;
	int y;
	int swipe;
}				t_snap;

t_list	*add_coordinate(t_list *list, int x, int y)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list) * 1);
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->next = list;
	}
	return (tmp);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("busy[%d][%d]\n", list->x, list->y);
		list = list->next;
	}
}

int		find_swipe(char **matrix, char obstacle, int x, int y, int swipe, t_list **list)
{
	int i;
	int j;
	int count;

	if (matrix[0][x + 1 + swipe] && matrix[y + 1 + swipe] && matrix[y][x] != obstacle)
	{
		i = y;
		while (i < y + 1 + swipe)
		{
			if (matrix[i][x + 1 + swipe] == obstacle)
			{
				while (i >= y)
				{
					count = 1;
					while (x + count + swipe >= x)
					{
						*list = add_coordinate(*list, x + count + swipe, i);
						//printf("arr[%d][%d]\n", i, x + count + swipe);
						count--;
					}
					i--;
				}
				return (swipe);
			}
			i++;
		}

		j = x;
		while (j <= x + 1 + swipe)
		{
			if (matrix[i][j] == obstacle || matrix[i][j + 1] == '\0')
			{
				while (j >= x)
				{
					count = i;
					while (count >= y)
					{
						*list = add_coordinate(*list, j, count);
						//printf("harr[%d][%d]\n", count, j);
						count--;
					}
					j--;
				}
				return (swipe);
			}
			j++;
		}
		swipe++;
		return (find_swipe(matrix, obstacle, x, y, swipe, list));
	}
	else
		return swipe;
}

t_snap	find_snapshot(char **matrix, t_binfo binfo)
{
	t_snap			snapshot;
	t_list			*list;
	unsigned int	i;
	int				j;
	int				swipe;

	list = NULL;
	snapshot.x = 0;
	snapshot.y = 0;
	snapshot.swipe = 0;
	i = 0;
	while (i < binfo.lines - 1)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			swipe = find_swipe(matrix, binfo.obstacle, j, i, 0, &list);
			if (swipe > snapshot.swipe)
			{
				snapshot.x = j;
				snapshot.y = i;
				snapshot.swipe = swipe;
			}
			j = j + 2 + swipe;
		}
		i++;
	}

	print_list(list);
	return (snapshot);
}

char **fill_matrix(char **matrix, t_snap snapshot, char full)
{
	int i;
	int j;

	i = snapshot.y;
	while (i <= snapshot.y + snapshot.swipe)
	{
		j = snapshot.x;
		while (j <= snapshot.x + snapshot.swipe)
		{
			matrix[i][j] = full;
			j++;
		}
		i++;
	}

	return (matrix);
}



char	**solve_matrix(char **matrix, t_binfo binfo)
{
	t_snap			snapshot;

	snapshot = find_snapshot(matrix, binfo);
	printf("arr[%d][%d] = %d swipes\n", snapshot.y, snapshot.x, snapshot.swipe);

	fill_matrix(matrix, snapshot, binfo.full);

	return matrix;
}

void	ft_fputchar(int fd, char c)
{
	write(fd, &c, 1);
}


int		main(int argc, char *argv[])
{
	int		fd;
	char	*fline;
	char	**matrix;
	t_binfo	binfo;
	char	*filename;
	char	c;

	if (argc == 1)
	{
		filename = "42";
		fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
		if (fd == -1)
		{
			ft_putstr("open() error\n");
			return (1);
		}
		while(read(STDIN_FILENO, &c, 1) > 0)
			ft_fputchar(fd, c);
	}
	else
	{
		filename = argv[1];
	}

	fd = open(filename, O_RDONLY);
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

	print_board(matrix);

	if (close(fd) < 0)
	{
		ft_putstr("close() failed\n");
		return (1);
	}

	free(fline);

	return (0);
}
