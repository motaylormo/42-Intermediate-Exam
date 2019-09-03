/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:12:49 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:39:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define	EXISTS(x, n)	(x >= 0 && x < n)
#define UNTOUCHED (-1)

static int	**make_log(int n, int **mine)
{
	int **log = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		log[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n - 1; j++)
			log[i][j] = UNTOUCHED;
		log[i][n - 1] = mine[i][n - 1];
	}
	return (log);
}

static int	max_of_3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	if (b > c)
		return (b);
	return (c);
}

static int	recurse(int n, int **mine, int **log, int x, int y)
{
	if (!(EXISTS(x,n) && EXISTS(y,n)))
	   return (0);
	if (log[y][x] == UNTOUCHED)
	{
		int n1 = recurse(n, mine, log, x + 1, y);//straight to the right
		int n2 = recurse(n, mine, log, x + 1, y - 1);//diagonally up to the right
		int n3 = recurse(n, mine, log, x + 1, y + 1);//diagonally down to the right
		log[y][x] = mine[y][x] + max_of_3(n1, n2, n3);
	}
	return (log[y][x]);
}

int		gold_gain(int **mine, int n)
{
	int	**log = make_log(n, mine);

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int curr = recurse(n, mine, log, 0, i);
		if (curr > max)
			max = curr;
	}
	return (max);
}
