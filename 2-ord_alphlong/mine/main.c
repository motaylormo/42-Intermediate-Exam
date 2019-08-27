/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:26:07 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 09:26:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

#define LOWERCASE(c) ((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c)

static void	bubble_sort(char **arr, int (*f)(char*, char*))
{
	int	swap;
	while (1)
	{
		swap = 0;
		for (int i = 1; arr[i]; ++i)
		{
			if ((*f)(arr[i - 1], arr[i]) == 0)
			{
				char *tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
				swap = 1;
			}
		}
		if (swap == 0)
			return ;
	}
}

static int	alpha_order(char *a, char *b)
{
	for (int i = 0; a[i] || b[i]; ++i)
	{
		if (LOWERCASE(a[i]) < LOWERCASE(b[i]))
			return (1);
		if ((LOWERCASE(a[i]) > LOWERCASE(b[i]))
			|| (a[i] && !b[i]))
			return (0);
	}
	return (1);
}

static int	len_order(char *a, char *b)
{
	if (ft_strlen(a) <= ft_strlen(b))
		return (1);
	return (0);
}

static void	ord_alphlong(char *str)
{
	char **arr;

	arr = ft_strsplit(str);
	bubble_sort(arr, alpha_order);
	bubble_sort(arr, len_order);

	for (int i = 0; arr[i]; ++i)
	{
		ft_putstr(arr[i]);
		if (arr[i + 1])
			ft_putstr((ft_strlen(arr[i]) == ft_strlen(arr[i + 1])) ? " " : "\n");
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	ft_putstr("\n");
	return (0);
}
