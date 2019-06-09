/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:56:01 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/08 18:56:02 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

#define TO_LOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)

int		compare_words(char *a, char *b)
{
	int len_a = ft_strlen(a);
	int len_b = ft_strlen(b);
	if (len_a != len_b)
		return (len_a - len_b);

	int i = 0;
	while (i < len_a && TO_LOWER(a[i]) == TO_LOWER(b[i]))
		++i;
	return (TO_LOWER(a[i]) - TO_LOWER(b[i]));
}

void	sort_words(char **words)
{
	int swapped = 1;

	while (swapped)
	{
		swapped = 0;
		for (int i = 1; words[i]; ++i)
		{
			if (compare_words(words[i - 1], words[i]) > 0)
			{
				swap(&words[i - 1], &words[i]);
				swapped = 1;
			}
		}
	}
}

void	print_words(char **words)
{
	int len = ft_strlen(words[0]);
	int	cur_len;

	for (int i = 0; words[i]; ++i)
	{
		cur_len = ft_strlen(words[i]);
		if (i != 0)
		{
			if (cur_len == len)
				ft_putstr(" ");
			else
			{
				len = cur_len;
				ft_putstr("\n");
			}
		}
		ft_putstr(words[i]);
	}
}

int		main(int argc, char **argv)
{
	char **words;

	if ((argc == 2) && (words = ft_strsplit(argv[1])))
	{
		sort_words(words);
		print_words(words);
		free(words);
	}
	write(1, "\n", 1);
	return (0);
}
