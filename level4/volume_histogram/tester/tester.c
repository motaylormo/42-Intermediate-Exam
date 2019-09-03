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

# define MAX_FOR_DIAGRAM 500
static int flag;

int		parse_flags(int argc, char **argv);
void	print_diagram(int *arr, int size);

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
	{0, 10, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 9, 0, 0, 0, 2, 0, 0, 0, 7, 0, 0, 0, 6, 0, 0, 0, 9, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0, 5, 0, 0, 0, 4, 0, 0, 7, 0, 0, 2, 1, 0},
	{2, 0, 0, 5, 6, 6, 5, 0, 0, 8, 9, 0, 5, 0, 0, 4, 0, 7, 0, 8, 0, 9, 0, 3, 0, 1, 0, 5, 0, 5, 0, 6, 0, 4, 0, 6, 0, 7, 0, 5, 5, 6, 5, 4, 7, 0, 8, 0, 5, 0, 0, 0},
	{0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0},
	{0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 8, 0, 2, 0, 5, 2, 0, 3, 0, 0}
};
static int	g_moul_tests_size[] = {
	1, 1, 3, 3, 18, 57, 52, 16, 20
};
static int	g_moul_answers[] = {
	0, 0, 1, 0, 17, 343, 211, 26, 46
};


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

void	run_test(int test_arr[MAX_ARR_SIZE], int test_size, int answer)
{
	int ret = volume_histogram(test_arr, test_size);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	print_array("histogram", test_arr, test_size);
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
	if (flag == 1)// && answer > 0 && test < MAX_FOR_DIAGRAM)
		print_diagram(test_arr, test_size);
}

void	run_test_set(char *str, int count, int test_arrs[][MAX_ARR_SIZE], int *test_size, int* answers)
{
	printf("\e[100m%s\e[0m\n", str);
	for (int i = 0; i < count; ++i)
	{
		printf("\e[1mTest %d:\e[0m ", i + 1);
		run_test(test_arrs[i], test_size[i], answers[i]);
		printf("\n");
	}
}

int		main(int argc, char **argv)
{
	flag = parse_flags(argc, argv);
	if (argc < 2 || (argc < 3 && flag))
	{
		run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT, g_subj_tests_arr, g_subj_tests_size, g_subj_answers);
		run_test_set("TESTS FROM TRACE", MOUL_TEST_COUNT, g_moul_tests_arr, g_moul_tests_size, g_moul_answers);
	}
	else
	{
		argc -= (flag) ? 2 : 1;
		argv += (flag) ? 2 : 1;

		int	*arr = malloc(sizeof(int) * argc);
		for (int i = 0; i < argc; ++i)
			arr[i] = atoi(argv[i]);
		print_array("histogram", arr, argc);
		printf("your return = %d\n", volume_histogram(arr, argc));
		if (flag == 1)
			print_diagram(arr, argc);
	}
}
