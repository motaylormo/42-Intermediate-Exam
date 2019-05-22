/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:22:42 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/22 14:22:43 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//	printf()
#include <stdlib.h>//	malloc

int	gold_gain(int **mine, int n);
/*
**	Runs tests from the subject.
**	(Moulinette tests are locked away in files and inaccessible.)
*/

#define	MAX_ARR_SIZE 4

int	**arr_to_ptr(int arr[MAX_ARR_SIZE][MAX_ARR_SIZE], int n)
{
	int	**ptr;

	ptr = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		ptr[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; ++j)
		{
			ptr[i][j] = arr[i][j];
		}
	}
	return (ptr);
}

void	print_map(int arr[MAX_ARR_SIZE][MAX_ARR_SIZE], int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("\t");
		for (int j = 0; j < n; ++j)
		{
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}

void	run_test(int mine[MAX_ARR_SIZE][MAX_ARR_SIZE], int n, int answer)
{
	print_map(mine, n);
	printf("should return = %d\n", answer);
	printf("  your return = %d\n", gold_gain(arr_to_ptr(mine,n), n));
}

void	subject_tests(void)
{
	printf("Example 1:\n");
	int mine1[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{ 1, 0, 0 },
		{ 0, 3, 4 },
		{ 0, 0, 0 },
	};
	int n1 = 3;
	run_test(mine1, n1, 8);

	printf("\nExample 2:\n");
	int mine2[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{ 1, 2, 3 },
		{ 3, 4, 8 },
		{ 9, 6, 7 },
	};
	int n2 = 3;
	run_test(mine2, n2, 23);

	printf("\nExample 3:\n");
	int mine3[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{ 1, 3, 1, 5 },
		{ 2, 2, 4, 1 },
		{ 5, 0, 2, 3 },
		{ 0, 6, 1, 2 },
	};
	int n3 = 4;
	run_test(mine3, n3, 16);
}

int		main(void)
{
	subject_tests();
}