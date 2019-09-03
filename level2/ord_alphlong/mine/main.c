/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:26:38 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:10:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ord_alphlong(char *str)
{
	char **words;
	int	len;

	if (!(words = ft_strsplit(str, &len)))
		return ;
	bubble_sort(words, len, alpha_order);
	bubble_sort(words, len, len_order);

	ft_putstr(words[0]);
	for (int i = 1; words[i]; i++)
	{
		ft_putstr(
				(ft_strlen(words[i]) == ft_strlen(words[i - 1])) ?
				" " : "\n");
		ft_putstr(words[i]);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	ft_putstr("\n");
	return (0);
}
