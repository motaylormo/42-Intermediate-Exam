/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:02:07 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 09:12:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define DIGIT(x)		(x >= 0 && x <= 9)
#define MINUS_A(n, a)	(n - (a * 10) - a)

/*
**	"AB + CA = n"
**		B = ones
**		c = tens
**		A = ones and tens
*/
void	equation(int n)
{
	for (int a = 0; DIGIT(a); a++)// "sorted in ascending order beginning with A"
	{
		int b = MINUS_A(n,a) % 10;
		int c = MINUS_A(n,a) / 10;
		if (DIGIT(b) && DIGIT(c))
			printf("A = %d, B = %d, C = %d\n", a, b, c);
	}
}
