/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:03:35 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:04:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

void	bubble_sort(char **arr, int len, int (*f)(char*, char*))
{
	for (int rounds = 0; rounds < len; rounds++)
	{
		for (int i = 1; i < len; i++)
		{
			if ((*f)(arr[i - 1], arr[i]) == 0)
			{
				char *tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

#define	LOWERCASE(c)	((c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c)
#define ALPH_GREATER(a, b)	((a && !b) || (LOWERCASE(a) > LOWERCASE(b)))
int	alpha_order(char *a, char *b)
{
	for (int i = 0; a[i] || b[i]; i++)
	{
		if (ALPH_GREATER(a[i], b[i]))
			return (0);
		if (ALPH_GREATER(b[i], a[i]))
			return (1);
	}
	return (1);
}

int	len_order(char *a, char *b)
{
	if (ft_strlen(a) <= ft_strlen(b))
		return (1);
	else
		return (0);
}
