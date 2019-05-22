/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:03:11 by exam              #+#    #+#             */
/*   Updated: 2019/05/21 09:03:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()
#include <stdlib.h>//	atoi()

int		find_pivot(int *arr, int n);

/*
**	Given no args, it runs tests from the subject.
**		(Moulinette tests are locked away in files and inaccessible.)
**	Given args, it runs those.
*/
#define	MAX_ARR_SIZE 10

#define SUBJ_TEST_COUNT 5
static int	g_subj_tests_arr[][MAX_ARR_SIZE] = {
	{1, 2, 3, 4, 0, 6},
	{-5, 10, 2, 5},
	{1, 100, 0, 0, 1},
	{7, 9, 8},
	{1 , 2},
};
static int	g_subj_tests_size[] = {
	6, 4, 5, 3, 2
};
static int	g_subj_answers[] = {
	3, 2, 1, -1, -1
};

void	print_array(char *name, int *arr, int size)
{
	printf("%s[] = {", name);
	for (int i = 0; i < size; ++i)
	{
		printf("%d", arr[i]);
		if (i + 1 < size)
			printf(", ");
	}
	printf("};\n");
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
	printf("%*c= %d\n", n_width, ' ', right_sum);
}

void	run_tests(int count, int tests_arr[][MAX_ARR_SIZE], int tests_size[], int answers[])
{
	for (int i = 0; i < count; ++i)
	{
		printf("Test %d:\n", i + 1);
		print_array("arr", tests_arr[i], tests_size[i]);
		printf("n = %d;\n", tests_size[i]);
		printf("find_pivot(arr, n);\n");
		print_diagram(tests_arr[i], tests_size[i], answers[i]);
		printf("should return = %d\n", answers[i]);
		printf("  your return = %d\n", find_pivot(tests_arr[i], tests_size[i]));
		if (i + 1 < count)
			printf("\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("TESTS FROM SUBJECT:\n");
		run_tests(SUBJ_TEST_COUNT, g_subj_tests_arr, g_subj_tests_size, g_subj_answers);
	}
	else
	{
		int	*arr = malloc(sizeof(int) * (argc - 1));
		for (int i = 1; i < argc; ++i)
			arr[i - 1] = atoi(argv[i]);
		print_array("arr", arr, argc - 1);
		printf("n = %d;\n", argc - 1);
		int ret = find_pivot(arr, argc - 1);
		if (ret != -1)
			print_diagram(arr, argc - 1, ret);
		printf("find_pivot(arr, n);\n");
		printf("your return = %d\n", ret);
	}
}
