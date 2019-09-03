/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 16:35:28 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 16:35:30 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void	print_diagram(int *arr, int size, int answer)
{
	if (answer == -1)
		return ;
	int	left_sum = 0;
	int	right_sum = 0;
	int	left_width = 0;
	int	right_width = 0;
	int	n_width;
	int	a_width;

	printf("\e[2m");
	printf("[ ");
	for (int i = 0; i < size; ++i)
	{
		if (i == answer)
			a_width = printf("(%d)", arr[i]);
		else
		{
			n_width = printf("%d", arr[i]);
			if (i < answer)
			{
				left_sum += arr[i];
				left_width += n_width;
			}
			if (i > answer)
			{
				right_sum += arr[i];
				right_width += n_width;
			}
		}
		if (i + 1 < size)
		{
			printf(", ");
			if (i + 1 < answer)
				left_width += 2;
			if (i > answer)
				right_width += 2;
		}
	}
	printf(" ]\n");

	printf("  ");
	for (int i = 0; i < left_width; ++i)
		printf("-");
	printf("  %*c^   ", a_width - 2, ' ');
	for (int i = 0; i < right_width; ++i)
		printf("-");
	printf("\n");

	n_width = left_width + right_width + a_width + 4;
	n_width -= printf(" = %d", left_sum);
	printf("%*c= %d", n_width, ' ', right_sum);
	printf("\n\e[0m");
}