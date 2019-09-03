/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:22:41 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/23 09:22:42 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()
#include <stdlib.h>//	malloc(), atoi()
#include <string.h>//	memcmp

int	**range_comb(int n);
/*
**	Given no args, it runs tests from the subject + moulinette tests.
**	Given args, it runs those.
*/
#define	MAX_ARR_SIZE 150

#define SUBJ_TEST_COUNT 2
static int	g_subj_tests[] = {2, 3};
static int	g_subj_answers[][MAX_ARR_SIZE][MAX_ARR_SIZE] = {
	{
		{0, 1},	{1, 0},
	},
	{
		{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0},
	},
};

//	The last two tests might be included later if I figure out a reasonable way to do so.
#define MOUL_TEST_COUNT 7//9
static int	g_moul_tests[] = {
	-1, 0, 1, 2, 3, 4, 5, //7, 8
};
static int	g_moul_answers[][MAX_ARR_SIZE][MAX_ARR_SIZE] = {
	{},//-1
	{},//0
	{//1
		{0}
	},
	{//2
		{0, 1}, {1, 0},
	},
	{//3
		{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0},
	},
	{//4
		{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1},
		{0, 3, 1, 2}, {0, 3, 2, 1}, {1, 0, 2, 3}, {1, 0, 3, 2},
		{1, 2, 0, 3}, {1, 2, 3, 0}, {1, 3, 0, 2}, {1, 3, 2, 0},
		{2, 0, 1, 3}, {2, 0, 3, 1}, {2, 1, 0, 3}, {2, 1, 3, 0},
		{2, 3, 0, 1}, {2, 3, 1, 0}, {3, 0, 1, 2}, {3, 0, 2, 1},
		{3, 1, 0, 2}, {3, 1, 2, 0}, {3, 2, 0, 1}, {3, 2, 1, 0},
	},
	{//5
		{0, 1, 2, 3, 4}, {0, 1, 2, 4, 3}, {0, 1, 3, 2, 4}, {0, 1, 3, 4, 2},
		{0, 1, 4, 2, 3}, {0, 1, 4, 3, 2}, {0, 2, 1, 3, 4}, {0, 2, 1, 4, 3},
		{0, 2, 3, 1, 4}, {0, 2, 3, 4, 1}, {0, 2, 4, 1, 3}, {0, 2, 4, 3, 1},
		{0, 3, 1, 2, 4}, {0, 3, 1, 4, 2}, {0, 3, 2, 1, 4}, {0, 3, 2, 4, 1},
		{0, 3, 4, 1, 2}, {0, 3, 4, 2, 1}, {0, 4, 1, 2, 3}, {0, 4, 1, 3, 2},
		{0, 4, 2, 1, 3}, {0, 4, 2, 3, 1}, {0, 4, 3, 1, 2}, {0, 4, 3, 2, 1},
		{1, 0, 2, 3, 4}, {1, 0, 2, 4, 3}, {1, 0, 3, 2, 4}, {1, 0, 3, 4, 2},
		{1, 0, 4, 2, 3}, {1, 0, 4, 3, 2}, {1, 2, 0, 3, 4}, {1, 2, 0, 4, 3},
		{1, 2, 3, 0, 4}, {1, 2, 3, 4, 0}, {1, 2, 4, 0, 3}, {1, 2, 4, 3, 0},
		{1, 3, 0, 2, 4}, {1, 3, 0, 4, 2}, {1, 3, 2, 0, 4}, {1, 3, 2, 4, 0},
		{1, 3, 4, 0, 2}, {1, 3, 4, 2, 0}, {1, 4, 0, 2, 3}, {1, 4, 0, 3, 2},
		{1, 4, 2, 0, 3}, {1, 4, 2, 3, 0}, {1, 4, 3, 0, 2}, {1, 4, 3, 2, 0},
		{2, 0, 1, 3, 4}, {2, 0, 1, 4, 3}, {2, 0, 3, 1, 4}, {2, 0, 3, 4, 1},
		{2, 0, 4, 1, 3}, {2, 0, 4, 3, 1}, {2, 1, 0, 3, 4}, {2, 1, 0, 4, 3},
		{2, 1, 3, 0, 4}, {2, 1, 3, 4, 0}, {2, 1, 4, 0, 3}, {2, 1, 4, 3, 0},
		{2, 3, 0, 1, 4}, {2, 3, 0, 4, 1}, {2, 3, 1, 0, 4}, {2, 3, 1, 4, 0},
		{2, 3, 4, 0, 1}, {2, 3, 4, 1, 0}, {2, 4, 0, 1, 3}, {2, 4, 0, 3, 1},
		{2, 4, 1, 0, 3}, {2, 4, 1, 3, 0}, {2, 4, 3, 0, 1}, {2, 4, 3, 1, 0},
		{3, 0, 1, 2, 4}, {3, 0, 1, 4, 2}, {3, 0, 2, 1, 4}, {3, 0, 2, 4, 1},
		{3, 0, 4, 1, 2}, {3, 0, 4, 2, 1}, {3, 1, 0, 2, 4}, {3, 1, 0, 4, 2},
		{3, 1, 2, 0, 4}, {3, 1, 2, 4, 0}, {3, 1, 4, 0, 2}, {3, 1, 4, 2, 0},
		{3, 2, 0, 1, 4}, {3, 2, 0, 4, 1}, {3, 2, 1, 0, 4}, {3, 2, 1, 4, 0},
		{3, 2, 4, 0, 1}, {3, 2, 4, 1, 0}, {3, 4, 0, 1, 2}, {3, 4, 0, 2, 1},
		{3, 4, 1, 0, 2}, {3, 4, 1, 2, 0}, {3, 4, 2, 0, 1}, {3, 4, 2, 1, 0},
		{4, 0, 1, 2, 3}, {4, 0, 1, 3, 2}, {4, 0, 2, 1, 3}, {4, 0, 2, 3, 1},
		{4, 0, 3, 1, 2}, {4, 0, 3, 2, 1}, {4, 1, 0, 2, 3}, {4, 1, 0, 3, 2},
		{4, 1, 2, 0, 3}, {4, 1, 2, 3, 0}, {4, 1, 3, 0, 2}, {4, 1, 3, 2, 0},
		{4, 2, 0, 1, 3}, {4, 2, 0, 3, 1}, {4, 2, 1, 0, 3}, {4, 2, 1, 3, 0},
		{4, 2, 3, 0, 1}, {4, 2, 3, 1, 0}, {4, 3, 0, 1, 2}, {4, 3, 0, 2, 1},
		{4, 3, 1, 0, 2}, {4, 3, 1, 2, 0}, {4, 3, 2, 0, 1}, {4, 3, 2, 1, 0},
	},
/*	{//7

	},
	{//8

	},*/
};

static void	print_array(int n, int **arr)
{
	if (arr == NULL)
	{
		printf("(NULL)\n");
		return ;
	}
	printf("{\n");
	for (int i = 0; arr[i]; ++i)
	{
		printf("  {");
		for (int j = 0; j < n; ++j)
		{
			printf("%d", arr[i][j]);
			if (j + 1 < n)
				printf(", ");
		}
		printf("},"); 
		if ((i + 1) % n == 0)
			printf("\n");
	}
	printf("}\n");
}

static int	factorial(int n)
{
	int	sum = 1;
	for (int i = n; i > 0; --i)
	{
		sum *= i;
	}
	return (sum);
}

static int	**arr_to_ptr(int arr[MAX_ARR_SIZE][MAX_ARR_SIZE], int n)
{
	if (n <= 0)
		return (NULL);

	int	n_fac = factorial(n);
	int	**ptr;

	ptr = malloc(sizeof(int*) * (n_fac + 1));
	for (int i = 0; i < n_fac; ++i)
	{
		ptr[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; ++j)
			ptr[i][j] = arr[i][j];
	}
	ptr[n_fac] = NULL;
	return (ptr);
}

static void	run_test(int n, int answer[MAX_ARR_SIZE][MAX_ARR_SIZE])
{
	int **your = range_comb(n);
	int	**corr = arr_to_ptr(answer, n);
	int status = 0;

	if (your && corr)
		for (int i = 0; (your[i] || corr[i]); ++i)
		{
			if (memcmp(your[i], corr[i], sizeof(int) * n) != 0)
			{
				status = 1;
				break;
			}
		}
	else if (your || corr)
		status = 1;

	printf((status == 0) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	printf("range_comb(%d);\n", n);
	printf("your return = ");
	print_array(n, your);
	if (status != 0)
	{
		printf("should return = ");
		print_array(n, corr);
	}
}

void	run_test_set(char *str, int count, int tests[], int answers[][MAX_ARR_SIZE][MAX_ARR_SIZE])
{
	printf("\e[100m%s\e[0m\n", str);
	for (int i = 0; i < count; ++i)
	{
		printf("\e[1mTest %d:\e[0m ", i + 1);
		run_test(tests[i], answers[i]);
		if (i + 1 < count)
			printf("\n");
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
		run_test_set("TESTS FROM TRACE", MOUL_TEST_COUNT, g_moul_tests, g_moul_answers);
	}
	else
	{
		int n = atoi(argv[1]);
		printf("range_comb(%d);\n", n);
		printf("your return = ");
		print_array(n, range_comb(n));
	}
}
