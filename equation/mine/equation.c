/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:03:09 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 09:03:10 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define DIGIT(d)	(d >= 0 && d <= 9)
#define AB_PLUS_CA(a, b, c)	(((a * 10) + b) + ((c * 10) + a))

/*
**	AB + CA = n
**
**	B = ones
**	C = tens
**	A = both ones and tens
*/

void	equation(int n)
{
	int	b;
	int	c;
	int	tmp;

	for (int a = 0; a < 10; ++a)
	{
		tmp = n - (a * 10 + a);
		b = tmp % 10;
		c = tmp / 10;
		if (DIGIT(b) && DIGIT(c) && AB_PLUS_CA(a, b, c) == n)
			printf("A = %d, B = %d, C = %d\n", a, b, c);
	}
}
