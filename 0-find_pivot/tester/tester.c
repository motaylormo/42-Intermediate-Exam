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
static int flag;

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

int		parse_flags(int argc, char **argv);
void	print_diagram(int *arr, int size, int answer);

void	print_array(char *arr_name, int *arr, char *size_name, int size)
{
	printf("\t%s[] = {", arr_name);
	for (int i = 0; i < size; ++i)
	{
		printf("%d", arr[i]);
		if (i + 1 < size)
			printf(", ");
	}
	printf("};\n");
	printf("\t%s = %d;\n", size_name, size);
}

void	run_test(int test_arr[MAX_ARR_SIZE], int test_size, int answer)
{
	int ret = find_pivot(test_arr, test_size);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	print_array("arr", test_arr, "n", test_size);
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
	if (flag == 1 && test_size > 0)
		print_diagram(test_arr, test_size, answer);
}

void	run_test_set(char *str, int count, int tests_arr[][MAX_ARR_SIZE], int tests_size[], int answers[])
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

int	main(int argc, char **argv)
{
	flag = parse_flags(argc, argv);
	if (argc < 2 || (argc < 3 && flag))
	{
		run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT,
					g_subj_tests_arr, g_subj_tests_size, g_subj_answers);
	}
	else
	{
		argc -= (flag) ? 2 : 1;
		argv += (flag) ? 2 : 1;

		int	*arr = malloc(sizeof(int) * argc);
		for (int i = 0; i < argc; ++i)
			arr[i] = atoi(argv[i]);
		int ret = find_pivot(arr, argc);
		print_array("arr", arr, "n", argc);
		printf("your return = %d\n", ret);
		if (flag == 1)
			print_diagram(arr, argc, ret);
	}	
}
