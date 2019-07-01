/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:22:42 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 14:22:43 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()
#include <stdlib.h>//	malloc

int	gold_gain(int **mine, int n);
/*
**	Runs tests from the subject.
**	(Moulinette tests are locked away in files and inaccessible.)
*/

#define	MAX_ARR_SIZE 4

#define SUBJ_TEST_COUNT 3
static int		g_subj_tests_arr[][MAX_ARR_SIZE][MAX_ARR_SIZE] = {
	{
		{ 1, 0, 0 },
		{ 0, 3, 4 },
		{ 0, 0, 0 },
	},
	{
		{ 1, 2, 3 },
		{ 3, 4, 8 },
		{ 9, 6, 7 },
	},
	{
		{ 1, 3, 1, 5 },
		{ 2, 2, 4, 1 },
		{ 5, 0, 2, 3 },
		{ 0, 6, 1, 2 },
	}
};
static int		g_subj_tests_size[] = {
	3, 3, 4
};
static int		g_subj_answers[] = {
	8, 23, 16
};

int	**arr_to_ptr(int arr[MAX_ARR_SIZE][MAX_ARR_SIZE], int n)
{
	int	**ptr;

	ptr = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		ptr[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; ++j)
		{
			ptr[i][j] = arr[i][j];
		}
	}
	return (ptr);
}

void	print_map(int arr[MAX_ARR_SIZE][MAX_ARR_SIZE], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("\t[ ");
		for (int j = 0; j < n; ++j)
		{
			printf("%d", arr[i][j]);
			if (j + 1 < n)
				printf(", ");
		}
		printf(" ]");
		if (i + 1 < n)
			printf(",");
		printf("\n");
	}
}

void	run_test(int mine[MAX_ARR_SIZE][MAX_ARR_SIZE], int n, int answer)
{
	int ret = gold_gain(arr_to_ptr(mine,n), n);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	print_map(mine, n);
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
}

void	run_test_set(char *str, int count, int tests_arr[][MAX_ARR_SIZE][MAX_ARR_SIZE],
								int tests_size[], int answers[])
{
	printf("\e[100m%s\e[0m\n", str);
	for (int i = 0; i < count; ++i)
	{
		printf("\e[1mTest %d:\e[0m ", i + 1);
		run_test(tests_arr[i], tests_size[i], answers[i]);
		if (i + 1 < count)
			printf("\n");
	}
}

int		main(void)
{
	run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT,
						g_subj_tests_arr, g_subj_tests_size, g_subj_answers);
}