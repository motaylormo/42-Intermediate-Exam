/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:54:01 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/09 11:54:36 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Implement a function which counts, for a given integer n,
**	the number of 2s that appear in all the numbers between 0 and n (inclusive).
*/

static int	nums_2s(int num, int twos)
{
	if (num % 10 == 2)
		twos++;
	if (num < 10)
		return (twos);
	else
		return (nums_2s(num / 10, twos));
}

int			count_of_2(int n)
{
	int	sum = 0;
	for (int i = 0; i <= n; ++i)
	{
		sum += nums_2s(i, 0);
	}
	return (sum);
}
