/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 09:04:59 by exam              #+#    #+#             */
/*   Updated: 2019/04/16 09:05:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int a_len, int *b, int b_len)
{
	int	tally = 0;
	int	ai = 0;
	int	bi = 0;

	while (ai < a_len && bi < b_len)
	{
		if (a[ai] < b[bi])
			ai++;
		if (a[ai] > b[bi])
			bi++;
		if (a[ai] == b[bi])
		{
			printf(((tally == 0) ? "%d" : " %d"), a[ai]);
			tally++;
			ai++;
			bi++;
		}
	}
	printf("\n");
}
