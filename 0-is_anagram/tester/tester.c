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

void	run_test(char *test[2], int answer)
{
	int ret = is_anagram(test[0], test[1]);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	printf("is_anagram(\"%s\", \"%s\");\n", test[0], test[1]);
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
}

void	run_test_set(char *str, int count, char *tests[][2], int* answers)
{
	printf("\e[100m%s\e[0m\n", str);
	for (int i = 0; i < count; ++i)
	{
		printf("\e[1mTest %d:\e[0m ", i + 1);
		run_test(tests[i], answers[i]);
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
	}
	else
	{
		printf("is_anagram(\"%s\", \"%s\");\n", argv[1], argv[2]);
		printf("your return = %d\n", is_anagram(argv[1], argv[2]));
	}
}