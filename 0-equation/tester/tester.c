/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:33:40 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 10:33:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()
#include <stdlib.h>//	atoi()

void	equation(int n);

/*
**	Given no args, it runs tests from the subject + moulinette tests.
**	Given args, it runs those.
*/

#define SUBJ_TEST_COUNT 3
static int		g_subj_tests[] = { 42, 111, 0 };
static char*	g_subj_answers[] = {
	"A = 0, B = 2, C = 4\nA = 1, B = 1, C = 3\nA = 2, B = 0, C = 2\nA = 3, B = 9, C = 0\n",
	"A = 2, B = 9, C = 8\nA = 3, B = 8, C = 7\nA = 4, B = 7, C = 6\nA = 5, B = 6, C = 5\nA = 6, B = 5, C = 4\nA = 7, B = 4, C = 3\nA = 8, B = 3, C = 2\nA = 9, B = 2, C = 1\n",
	"A = 0, B = 0, C = 0\n"
};

#define MOUL_TEST_COUNT 9
static int	g_moul_tests[] = {
	0, 3, 31, 42, 54, 21, 111, 133, 198
};
static char*	g_moul_answers[] = {
	"A = 0, B = 0, C = 0\n",
	"A = 0, B = 3, C = 0\n",
	"A = 0, B = 1, C = 3\nA = 1, B = 0, C = 2\nA = 2, B = 9, C = 0\n",
	"A = 0, B = 2, C = 4\nA = 1, B = 1, C = 3\nA = 2, B = 0, C = 2\nA = 3, B = 9, C = 0\n",
	"A = 0, B = 4, C = 5\nA = 1, B = 3, C = 4\nA = 2, B = 2, C = 3\nA = 3, B = 1, C = 2\nA = 4, B = 0, C = 1\n",
	"A = 0, B = 1, C = 2\nA = 1, B = 0, C = 1\n",
	"A = 2, B = 9, C = 8\nA = 3, B = 8, C = 7\nA = 4, B = 7, C = 6\nA = 5, B = 6, C = 5\nA = 6, B = 5, C = 4\nA = 7, B = 4, C = 3\nA = 8, B = 3, C = 2\nA = 9, B = 2, C = 1\n",
	"A = 4, B = 9, C = 8\nA = 5, B = 8, C = 7\nA = 6, B = 7, C = 6\nA = 7, B = 6, C = 5\nA = 8, B = 5, C = 4\nA = 9, B = 4, C = 3\n",
	"A = 9, B = 9, C = 9\n"
};

void	run_test(int test, char* answer)
{
	printf("equation(%d);\n", test);
	printf("your output:\n");
	equation(test);
	printf("correct output:\n");
	printf("%s", answer);
}

void	run_test_set(char *str, int count, int *tests, char* answers[])
{
	printf("\e[100m%s\e[0m\n", str);
	for (int i = 0; i < count; ++i)
	{
		printf("\e[1mTest %d:\e[0m\n", i + 1);
		run_test(tests[i], answers[i]);
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
		int arg = atoi(argv[1]);
		printf("equation(%d);\n", arg);
		printf("your output:\n");
		equation(arg);
	}
}