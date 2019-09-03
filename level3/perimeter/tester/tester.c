/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 11:11:01 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 11:11:08 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

#define N(value, left, right)	&(struct s_node){value, right, left}
#define L(value)	N(value, NULL, NULL)//leaf node

void	perimeter(struct s_node *root);

void	run_test(struct s_node *tree, char *answer)
{
	printf("   your output: ");
	perimeter(tree);
	printf("correct output: %s", answer);
}

void subject_tests(void)
{
	printf("\e[100mTESTS FROM SUBJECT\e[0m\n");
	
	printf("\e[1mTest 1:\e[0m\n");
	struct s_node *tree = N(92,
		N(85,
			N(79,
				NULL,
				N(10,
					N(39,
						N(35, L(96), NULL),
						(NULL)
					),
					(NULL)
				)
			),
			NULL),
		N(26,
			NULL,
			N(64,
				N(40,
					N(88,
						N(12, L(58), NULL),
						N(55, L(58), L(41))
					),
					N(10,
						N(52, L(22), L(35)),
						N(87, NULL, L(31))
					)
				),
				N(78,
					N(2,
						N(33, NULL, L(55)),
						N(11, L(99), NULL)
					),
					N(85, NULL, L(51))
				)
			)
		)
	);
	char *answer = "92 85 79 96 58 58 41 22 35 31 55 99 51 85 78 64 26\n";
	run_test(tree, answer);
}

int main(void)
{
	subject_tests();
	return (0);
}
