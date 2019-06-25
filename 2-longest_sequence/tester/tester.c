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

int		longest_sequence(struct s_node *node);

#define SUBJ_TEST_COUNT 4
static struct s_node	*g_subj_tests[] = {
	N(10, N(5, N(6, L(7), L(13)), L(9)), NULL),
	N(5, L(6), N(4, N(9, L(3), L(2)), N(3, NULL, L(2)))),
	N(30, N(15, L(61), NULL), N(41, NULL, L(80))),
	NULL,
};
static int g_subj_answers[] = { 3, 2, 1, 0 };

void	run_test(struct s_node *tree, int answer)
{
	int	ret = longest_sequence(tree);
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
		run_test(g_subj_tests[i], g_subj_answers[i]);
	}
	return (0);
}
