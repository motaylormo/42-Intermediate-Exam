/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:22:58 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 12:22:58 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>//	printf()
#include <stdlib.h>//	atoi() & malloc()

int		volume_histogram(int *histogram, int size);

/*
**	Given no args, it runs tests from the subject + moulinette tests.
**	Given args, it runs those.
*/
#define	MAX_ARR_SIZE 100

#define SUBJ_TEST_COUNT 2
static int	g_subj_tests_arr[][MAX_ARR_SIZE] = {
	{1, 0, 2, 0, 2},
	{0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0}
};
static int	g_subj_tests_size[] = {
	5, 16
};
static int	g_subj_answers[] = {
	3, 26
};

#define MOUL_TEST_COUNT 9
static int	g_moul_tests_arr[][MAX_ARR_SIZE] = {
	{0},
	{1},
	{1, 0, 1},
	{0, 1, 0},
	{0, 1, 0, 5, 0, 0, 3, 3, 3, 0, 0, 1, 0, 0, 2, 2, 0, 1},
	{0, 10, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 9, 0, 0,
		 0, 2, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 9, 0, 0, 0, 4, 0,
		 0, 0, 3, 0, 0, 5, 0, 0, 0, 4, 0, 0, 7, 0, 0, 2, 1, 0},
	{2, 0, 0, 5, 6, 6, 5, 0, 0, 8, 9, 0, 5, 0, 0, 4, 0, 7, 0, 8,
		0, 9, 0, 3, 0, 1, 0, 5, 0, 5, 0, 6, 0, 4, 0, 6, 0, 7, 0,
		5, 5, 6, 5, 4, 7, 0, 8, 0, 5, 0, 0, 0},
	{0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0},
	{0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0}
};
static int	g_moul_tests_size[] = {
	1, 1, 3, 3, 18, 57, 52, 16, 20
};
static int	g_moul_answers[] = {
	0, 0, 1, 0, 17, 343, 211, 26, 46
};

# define BOLD	"\e[1m"
# define DIM	"\e[2m"
# define OFF	"\e[0m"

void	print_array(char *name, int *arr, int size)
{
	printf("\t%s[] = {", name);
	for (int i = 0; i < size; ++i)
	{
		printf("%d", arr[i]);
		if (i + 1 < size)
			printf(", ");
	}
	printf("};\n");
	printf("\tsize = %d;\n", size);
}

int		is_walled(int *arr, int size, int index, int level)
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
	printf(DIM);
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
	printf(OFF "\n");
}

void	run_test(int tests_arr[MAX_ARR_SIZE], int tests_size, int answer)
{
	int ret = volume_histogram(tests_arr, tests_size);
	if (ret == answer)
		printf("\e[3;32mCorrect\e[0m\n");
	else
		printf("\e[3;31mIncorrect\e[0m\n");
	print_array("histogram", tests_arr, tests_size);
	if (ret == answer)
		printf("return = %d\n", ret);
	else
	{
		printf("should return = %d\n", answer);
		printf("  your return = %d\n", ret);
	}
	print_diagram(tests_arr, tests_size);

	printf("\n");
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf(BOLD "TESTS FROM SUBJECT:" OFF "\n");
		for (int i = 0; i < SUBJ_TEST_COUNT; ++i)
		{
			printf(BOLD "Test %d:" OFF " ", i + 1);
			run_test(g_subj_tests_arr[i], g_subj_tests_size[i], g_subj_answers[i]);
		}
		printf("\n");
		printf(BOLD "TESTS FROM TRACE:" OFF "\n");
		for (int i = 0; i < MOUL_TEST_COUNT; ++i)
		{
			printf(BOLD "Test %d:" OFF " ", i + 1);
			run_test(g_moul_tests_arr[i], g_moul_tests_size[i], g_moul_answers[i]);
		}
	}
	else
	{
		int	*arr = malloc(sizeof(int) * (argc - 1));
		for (int i = 1; i < argc; ++i)
			arr[i - 1] = atoi(argv[i]);
		print_array("histogram", arr, argc - 1);
		printf("return = %d\n", volume_histogram(arr, argc - 1));
		print_diagram(arr, argc - 1);
	}
}
