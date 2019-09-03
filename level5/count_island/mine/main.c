/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:57:24 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 12:05:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		count_island(int fd)
{
	char	**map;
	if (!(map = read_in_file(fd)))
		return (0);

	char	digit = '0';
	for (int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
		{
			if (map[i][j] == 'X')
			{
				if (digit > '9')
					return (0);
				flood_fill(map, i, j, digit++);
			}
		}
	}

	for (int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc == 2 &&
			(fd = open(argv[1], O_RDONLY))
			&& count_island(fd))
		;
	else
		ft_putchar('\n');
}
