/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:15:11 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 10:15:12 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()
#include <stdlib.h>//	atoi()

int		count_of_2(int n);
/*
**	Given no args, it runs tests from the subject + moulinette tests.
**	Given args, it runs those.
*/

#define SUBJ_TEST_COUNT 1
static int	g_subj_tests[] = { 25 };
static int	g_subj_answers[] = { 9 };

#define MOUL_TEST_COUNT 9
static int	g_moul_tests[] = {
	-1, 0, 1, 13, 3, 25, 300, 1000, 424242
};
static int	g_moul_answers[] = {
	0, 0, 0, 2, 1, 9, 160, 300, 314541
};

void	run_tests(int count, int *tests, int* answers)
{
	for (int i = 0; i < count; ++i)
	{
		printf("Test %d:\n", i + 1);
		printf("count_of_2(%d);\n", tests[i]);
		printf("should return = %d\n", answers[i]);
		printf("  your return = %d\n", count_of_2(tests[i]));
		if (i + 1 < count)
			printf("\n");
	}
}

int	main(int argc, char **argv)
{
	int	arg;

	if (argc < 2)
	{
		printf("TESTS FROM SUBJECT:\n");
		run_tests(SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
		printf("\nTESTS FROM TRACE:\n");
		run_tests(MOUL_TEST_COUNT, g_moul_tests, g_moul_answers);
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			arg = atoi(argv[i]);
			printf("Test %d:\n", i);
			printf("count_of_2(%d);\n", arg);
			printf("your return = %d\n", count_of_2(arg));
			if (i + 1 < argc)
				printf("\n");
		}
	}
}