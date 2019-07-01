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

# define MAX_FOR_DIAGRAM 500
static int flag;

int		count_of_2(int n);
int		parse_flags(int argc, char **argv);
void	print_diagram(int n);
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

void	run_test(int test, int answer)
{
	int ret = count_of_2(test);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	printf("count_of_2(%d);\n", test);
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
	if (flag == 1 && answer > 0 && test < MAX_FOR_DIAGRAM)
		print_diagram(test);
}

void	run_test_set(char *str, int count, int *tests, int* answers)
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
	flag = parse_flags(argc, argv);
	if (argc < 2 || (argc < 3 && flag))
	{
		run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
		run_test_set("TESTS FROM TRACE", MOUL_TEST_COUNT, g_moul_tests, g_moul_answers);
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			int arg = atoi(argv[i]);
			printf("\n\e[1mTest %d:\e[0m\n", i);
			printf("count_of_2(%d);\n", arg);
			printf("your return = %d\n", count_of_2(arg));
			if (flag == 1)
				print_diagram(arg);
		}
	}
}