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

void	reverse_tree(struct s_node *root);

int	tree_match(struct s_node *a, struct s_node *b)
{
	if (!a && !b)
		return (1);
	if (a && b && (a->value == b->value))
	{
		int left = tree_match(a->left, b->left);
		int right = tree_match(a->right, b->right);
		return ((right == 1 && left == 1) ? 1 : 0);
	}
	return (0);
}

void	run_test(struct s_node *tree, struct s_node *answer)
{
	reverse_tree(tree);
	if (tree_match(tree, answer))
		printf("\e[3;32mCorrect\e[0m\n");
	else
		printf("\e[3;31mIncorrect\e[0m\n");
}

void	print_tree(struct s_node *n)
{
	if (n && (n->left || n->right))
	{
		printf("%d[", n->value);
		if (n->left)
			printf("l:%d.", n->left->value);
		if (n->right)
			printf("r:%d.", n->right->value);
		printf("]\n");
		print_tree(n->left);
		print_tree(n->right);
	}
}

void subject_tests(void)
{
	printf("\e[100mTESTS FROM SUBJECT\e[0m\n");
	
	printf("\e[1mTest 1:\e[0m ");
	struct s_node *tree = N(94,
		N(34,
			N(1, L(20), NULL),
			N(99,
				N(83, NULL, L(61)),
				N(39, L(37), L(67))
			)),
		L(52));
	struct s_node *answer = N(94,
		L(52),
		N(34,
			N(99,
				N(39, L(67), L(37)),
				N(83, L(61), NULL)
			),
			N(1, NULL, L(20))
		)
	);
	run_test(tree, answer);
}

int main(void)
{
	subject_tests();
	return (0);
}
