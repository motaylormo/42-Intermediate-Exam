/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:49:39 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 18:49:40 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//	getopt()
#include <stdio.h>//	printf()

int		parse_flags(int argc, char **argv)
{
	int	c;
	int flag = 0;
	while ((c = getopt(argc, argv, "d")) != -1)
	{
		if (c == 'd')
			flag = 1;
	}
	return (flag);
}

static int	is_walled(int *arr, int size, int index, int level)
{
	int	left = 0;
	int right = 0;
	for (int i = 0; i < size; ++i)
	{
		if (i < index && (arr[i] > level))
			left = 1;
		if (i > index && (arr[i] > level))
			right = 1;
	}
	return ((left && right) ? 1 : 0);
}

void	print_diagram(int *arr, int size)
{
	int	max = arr[0];
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("\e[2m");
	for (int level = max - 1; level >= 0; --level)
	{
		for (int i = 0; i < size; ++i)
		{
			if (i > 0)
				printf(" ");
			if (arr[i] > level)
				printf("#");
			else if (is_walled(arr, size, i, level))
				printf(".");
			else
				printf(" ");
		}
		printf("\n");
	}
	for (int i = 0; i < (size * 2) - 1; ++i)
		printf("-");
	printf("\n\e[0m");
}