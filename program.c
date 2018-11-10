/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmyrzata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:00:14 by bmyrzata          #+#    #+#             */
/*   Updated: 2018/11/10 15:48:45 by bmyrzata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define FLINE_MAX_SIZE 15

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

int		main(int argc, char *argv[])
{
	int		fd;
	char	*fline;
	//int		line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open() failed\n");
			return (1);
		}

		fline = get_fline(fd);
		ft_putstr(fline);
		ft_putchar('\n');
		// line = ft_atoi(fline);

		if (close(fd) < 0)
		{
			ft_putstr("close() failed\n");
			return (1);
		}
	}

	return (0);
}
