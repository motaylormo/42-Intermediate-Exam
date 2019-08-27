/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:23:04 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/26 20:23:05 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

char	**read_file(char *filename)
{
	int		fd;
	int		len;
	char	buf[MAXSIZE + 1];
	char	**arr;

	if (!(fd = open(filename, O_RDONLY)))
		return (NULL);
	arr = malloc(sizeof(char*) * MAXSIZE);
	for (int i = 0; i < MAXSIZE; ++i)
		arr[i] = NULL;
	len = 0;
	while ((read(fd, buf + len, 1)))
	{
		if (buf[len++] == '\n')
			break;
	}
	for (int i = 0; ; ++i)
	{
		if (!(ft_strchr(buf, '\n') == buf + (len - 1)))
			return (NULL);
		arr[i] = malloc(len);
	//	arr[i] = ft_strncpy(arr[i], buf, len - 1);
		
		for (int j = 0; j < len - 1; ++j)
		{
			if (buf[j] != 'X' && buf[j] != '.')
				return (NULL);
			arr[i][j] = buf[j];
		}
		arr[i][len - 1] = '\0';

		if (!(read(fd, buf, len)))
			break;
	}
	return (arr);
}

t_point	get_size(char **arr)
{
	t_point	size;

	size.y = 0;
	while (arr[size.y])
		size.y++;
	size.x = 0;
	while (arr[0][size.x])
		size.x++;
	return (size);
}

void	count_island(char *filename)
{
	char **arr;
	if (!(arr = read_file(filename)))
	{
		ft_putchar('\n');
		return;
	}
	t_point	size = get_size(arr);

	char	digit = '0';
	for (int row = 0; arr[row]; ++row)
	{
		for (int col = 0; arr[row][col]; ++col)
		{
			if (arr[row][col] == 'X')
			{
				flood_fill(arr, size, (t_point){col, row}, digit);
				digit++;
			}
		}
	}

	for (int y = 0; y < size.y; ++y)
	{
		for (int x = 0; x < size.x; ++x)
		{
			ft_putchar(arr[y][x]);
		}
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		count_island(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}