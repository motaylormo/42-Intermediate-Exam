/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:55:40 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/25 12:55:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "t_point.h"

void	flood_fill(char **tab, t_point size, t_point begin);
/*
**	Runs tests from the subject.
**	(Moulinette tests are locked away in files and inaccessible.)
*/

static char**	make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return new;
}

void	print_map(char *pre, char **area, t_point size, t_point begin)
{
	for (int i = 0; i < size.y; ++i)
	{
		printf("%s", pre);
		for (int j = 0; j < size.x; ++j)
		{
			printf(" ");
			if (i == begin.y && j == begin.x)
				printf("\e[100;1m");
			printf((area[i][j] == 'F') ? "\e[37m" : "\e[2m");
			printf("%c\e[0m", area[i][j]);
		}
		printf("\n");
	}
}

int		matrix_equal(char **a, char **b, t_point size)
{
	for (int i = 0; i < size.y; ++i)
	{
		if (!(strncmp(a[i], b[i], size.x) == 0))
			return (0);
	}
	return (1);
}

void	run_test(char **area, t_point size, t_point begin, char **answer)
{
	char **test = make_area(area, size);

	flood_fill(area, size, begin);
	int ret = matrix_equal(area, answer, size);
	printf((ret == 1) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	print_map("\t", test, size, begin);
	printf("your result:\n");
	print_map(" ", area, size, begin);
	if (!ret)
	{
		printf("should result:\n");
		print_map(" ", answer, size, begin);
	}
}

void	subject_tests(void)
{
	printf("\e[100mTESTS FROM SUBJECT\e[0m\n");
	printf("\e[1mTest 1:\e[0m ");
	t_point begin = {7, 4};
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	char *answer[] = {
		"FFFFFFFF",
		"F000F00F",
		"F00F000F",
		"F0FF000F",
		"FFF0000F"
	};
	run_test(make_area(zone, size), size, begin, make_area(answer, size));
}

int main(void)
{
	subject_tests();
	return (0);
}
