/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:09:44 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 12:09:45 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()

void	print_doublon(int *a, int na, int *b, int nb);
/*
**	Runs tests from the subject.
**	(Moulinette tests are locked away in files and inaccessible.)
*/

#define	MAX_ARR_SIZE 11

#define SUBJ_TEST_COUNT 3
static int		g_subj_tests_arr[][2][MAX_ARR_SIZE] = {
	{
		{ 1,  2, 10, 15 },
		{ 2, 20, 40, 70 }
	},
	{
		{ -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000 },
		{  2,  4,  5,  6,  7, 10,  40,  70 }
	},
	{
		{ 100,  200, 300 },
		{   1,    2,   3, 4 }
	}
};
static int		g_subj_tests_size[][2] = {
	{4, 4},
	{11, 8},
	{3, 4}
};
static char*	g_subj_answers[] = {
	"2\n",
	"2 10 70\n",
	"\n"
};

void	print_array(int *arr, int count)
{
	printf(" { ");
	for (int i = 0; i < count; ++i)
	{
		printf("%d", arr[i]);
		if (i + 1 < count)
			printf(", ");
	}
	printf(" }, %d", count);
}

void	run_tests(int count, int tests_arr[][2][MAX_ARR_SIZE], int tests_size[][2], char* answers[])
{
	for (int i = 0; i < count; ++i)
	{
		printf("Test %d:\n", i + 1);
		printf("print_doublon(");
		print_array(tests_arr[i][0], tests_size[i][0]);
		printf(",\n              ");
		print_array(tests_arr[i][1], tests_size[i][1]);
		printf(");\n");

		printf("correct output:\n");
		printf("%s", answers[i]);
		printf("your output:\n");
		print_doublon(tests_arr[i][0], tests_size[i][0],
					  tests_arr[i][1], tests_size[i][1]);
		if (i + 1 < count)
			printf("\n");
	}
}

int		main(void)
{
	printf("TESTS FROM SUBJECT:\n");
	run_tests(SUBJ_TEST_COUNT, g_subj_tests_arr, g_subj_tests_size, g_subj_answers);
}
