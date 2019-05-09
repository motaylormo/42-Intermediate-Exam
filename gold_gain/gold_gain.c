/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:22:48 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 10:22:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define IN_BOUNDS(x, n)			(x >= 0 && x < n)
#define POINT_EXIST(x, y, n)	(IN_BOUNDS(x, n) && IN_BOUNDS(y, n))
#define UNTOUCHED (-1)
#define LAST (n - 1)

#define R_ACROSS	row + 1, col		//straight to the right
#define R_UP		row + 1, col - 1	//diagonally up to the right
#define R_DOWN		row + 1, col + 1	//diagonally down to the right

static int	**create_arr(int n, int **mine)
{
	int	**arr;

	arr = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i)
	{
		arr[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; ++j)
		{
			if (j == LAST)
				arr[i][j] = mine[i][j];
			else
				arr[i][j] = UNTOUCHED;
		}
	}
	return (arr);
}

static int	check_point(int **arr, int n, int row, int col)
{
	if (!POINT_EXIST(row, col, n))
		return (0);
	return (arr[col][row]);
}

static int	max_of_3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > c)
		return (b);
	else
		return (c);
}

static void	gg_recurse(int **mine, int n, int **log, int row, int col)
{
	if (!POINT_EXIST(row, col, n) || (log[col][row] != UNTOUCHED))
		return ;
	gg_recurse(mine, n, log, R_ACROSS);
	gg_recurse(mine, n, log, R_UP);
	gg_recurse(mine, n, log, R_DOWN);
	log[col][row] = mine[col][row] + max_of_3(check_point(log, n, R_ACROSS),
											  check_point(log, n, R_UP),
											  check_point(log, n, R_DOWN));
}

/*
**	Initially the miner is at first column but can be at any row.
*/
int		gold_gain(int **mine, int n)
{
	int	**log;
	int	max;

	log = create_arr(n, mine);
	for (int i = 0; i < n; ++i)
	{
		gg_recurse(mine, n, log, 0, i);
	}
	max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (log[i][0] > max)
			max = log[i][0];
	}
	return (max);
}
