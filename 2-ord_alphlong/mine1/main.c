/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:04:52 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 10:43:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

int		alpha_order(char *a, char *b)
{
	int i = 0;
	while (a[i] && b[i])
	{
		if (ft_tolower(a[i]) < ft_tolower(b[i]))
			return (1);
		if (ft_tolower(a[i]) > ft_tolower(b[i]))
			return (0);
		if (ft_tolower(a[i]) == ft_tolower(b[i]))
			i++;
	}
	if (a[i] && !b[i])
		return (0);
	return (1);
}

void	bubble_sort(char **arr)
{
	char *tmp;

	for (int r = 0; arr[r]; ++r)
	{
		for (int i = 1; arr[i]; ++i)
		{
			if (!alpha_order(arr[i - 1], arr[i]))
			{
				tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void	ord_alphlong(char *str)
{
	char	**words;
	int		tally;
	
	words = ft_strsplit(str);
	bubble_sort(words);
	for (int len = 1; len <= ft_strlen(str); ++len)
	{
		tally = 0;
		for (int i = 0; words[i]; ++i)
		{
			if (ft_strlen(words[i]) == len)
			{
				if (tally > 0)
					ft_putstr(" ");
				ft_putstr(words[i]);
				tally++;
			}
		}
		if (tally > 0)
			ft_putstr("\n");
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	else
		ft_putstr("\n");
	return (0);
}
