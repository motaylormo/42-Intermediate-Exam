/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:24:31 by mtaylor           #+#    #+#             */
/*   Updated: 2019/04/16 15:24:33 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define IS_ALPHA(c)	((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

static int	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A') + 'a');
	else
		return (c);
}

static void	count_ascii(char *s, int *index)
{
	while (*s)
	{
		index[to_lower(*s)]++;
		s++;
	}
}

void	count_alpha(char *s)
{
	int	index[127] = {0};
	int	tally = 0;

	count_ascii(s, (int*)&index);

	while (*s)
	{
		if (IS_ALPHA(*s) && index[to_lower(*s)] != -1)
		{
			printf((tally == 0) ? "%d%c" : ", %d%c",
				index[to_lower(*s)], to_lower(*s));
			index[to_lower(*s)] = -1;
			tally++;
		}
		s++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
	return (0);
}
