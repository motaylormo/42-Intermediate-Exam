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

int		width_tree(struct s_node *n);

#define SUBJ_TEST_COUNT 5
static struct s_node	*g_subj_tests[] = {
	N(1, N(2, L(3), N(4, L(6), NULL)), N(5, L(7), L(8))),
	N(1, N(2, N(4, N(5, NULL, L(8)), L(6)), N(7, N(9, L(11), L(12)), N(10, NULL, L(13)))), L(3)),
	N(10, NULL, L(12)),
	N(25, N(33, L(12), N(9, L(3), NULL)), NULL),
	L(10),
};
static int g_subj_answers[] = { 6, 7, 2, 4, 1 };


void	run_test(struct s_node *tree, int answer)
{
	int	ret = width_tree(tree);
	if (ret == answer)
		printf("\e[3;32mCorrect\e[0m\n");
	else
		printf("\e[3;31mIncorrect\e[0m\n");
	printf("should return = %d\n", answer);
	printf("  your return = %d\n", ret);
}

int main(void)
{
	printf("TESTS FROM SUBJECT:\n");
	for (int i = 0; i < SUBJ_TEST_COUNT; ++i)
	{
		printf("\nExample %d: ", i + 1);
		run_test(g_subj_tests[i], g_subj_answers[i]);
	}
	return (0);
}
