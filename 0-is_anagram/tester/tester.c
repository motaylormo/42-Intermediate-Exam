/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:06:03 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 11:06:04 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()

int	is_anagram(char *a, char *b);
/*
**	Given no args, it runs tests from the subject.
**		(Moulinette tests are locked away in files and inaccessible.)
**	Given args, it runs those.
*/

#define SUBJ_TEST_COUNT 3
static char*	g_subj_tests[][2] = {
	{"abcdef", "fabcde"},
	{".123?.", "?321.."},
	{"abca", "bcab"}
};
static int	g_subj_answers[] = { 1, 1, 0 };

void	run_tests(int count, char *tests[][2], int* answers)
{
	for (int i = 0; i < count; ++i)
	{
		printf("Test %d:\n", i + 1);
		printf("is_anagram(\"%s\", \"%s\");\n", tests[i][0], tests[i][1]);
		printf("should return = %d\n", answers[i]);
		printf("  your return = %d\n", is_anagram(tests[i][0], tests[i][1]));
		if (i + 1 < count)
			printf("\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("TESTS FROM SUBJECT:\n");
		run_tests(SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
	}
	else
	{
		for (int i = 1; i + 1 < argc; i += 2)
		{
			printf("Test %d:\n", i);
			printf("is_anagram(\"%s\", \"%s\");\n", argv[i], argv[i + 1]);
			printf("your return = %d\n", is_anagram(argv[i], argv[i + 1]));
			if (i + 2 < argc)
				printf("\n");
		}
	}
}