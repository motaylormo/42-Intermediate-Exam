/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:05:14 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/25 14:05:15 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};
#define N(value, left, right)	&(struct s_node){value, left, right}
#define L(value)	N(value, NULL, NULL)//leaf node

int		can_split(struct s_node *n);

#define SUBJ_TEST_COUNT 4
static struct s_node	*g_subj_tests[] = {
	N(28, N(51, N(26, L(76), L(13)), L(48)), NULL),
	N(30, N(15, L(61), NULL), N(41, L(80), NULL)),
	N(10, NULL, L(12)),
	N(5, L(1), N(6, N(7, L(3), L(2)), N(4, NULL, L(8)))),
};
static int g_subj_answers[] = { 1, 0, 1, 0 };

void	run_test(struct s_node *tree, int answer)
{
	int	ret = can_split(tree);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
}

void	run_test_set(char *str, int count, struct s_node *tests[], int* answers)
{
	printf("\e[100m%s\e[0m\n", str);
	for (int i = 0; i < count; ++i)
	{
		printf("\e[1mTest %d:\e[0m ", i + 1);
		run_test(tests[i], answers[i]);
		printf("\n");
	}
}

int main(void)
{
	run_test_set("TESTS FROM SUBJECT", SUBJ_TEST_COUNT, g_subj_tests, g_subj_answers);
	return (0);
}
