/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:19:07 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 17:19:08 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()

struct s_node {
	int				value;
	struct s_node	*next;
};
#define N(value, next)	&(struct s_node){value, next}

int		is_looping(struct s_node *node);

void	run_test(struct s_node *test, int answer)
{
	int ret = is_looping(test);
	printf((ret == answer) ? "\e[3;32mCorrect\e[0m\n" : "\e[3;31mIncorrect\e[0m\n");
	printf("  your return = %d\n", ret);
	if (ret != answer)
		printf("should return = %d\n", answer);
	printf("\n");
}

void	subject_tests(void)
{
	printf("\e[100mTESTS FROM SUBJECT\e[0m\n");
	printf("\e[1mTest 1:\e[0m ");
	struct s_node	*list1 = N(1, N(2, N(3, N(4, N(5, N(6, NULL))))));
	list1->next->next->next->next->next->next = list1->next->next;
	run_test(list1, 1);

	printf("\e[1mTest 2:\e[0m ");
	struct s_node	*list2 = N(12, N(150, N(30, N(50, N(345, N(120, N(200, NULL)))))));
	list2->next->next->next->next->next->next->next = list2->next;
	run_test(list2, 1);

	printf("\e[1mTest 3:\e[0m ");
	struct s_node	*list3 = N(12, N(150, N(30, N(50, N(345, N(120, NULL))))));
	run_test(list3, 0);

	printf("\e[1mTest 4:\e[0m ");
	struct s_node	*list4 = N(12, N(19, N(14, NULL)));
	list4->next->next->next = list4->next->next;
	run_test(list4, 1);
}

int	main(void)
{
	subject_tests();
}