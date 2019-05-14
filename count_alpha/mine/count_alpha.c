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
#define USED -1

static int	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A') + 'a');
	else
		return (c);
}

static void	count_ascii(char *s, int *hashtable)
{
	while (*s)
	{
		hashtable[to_lower(*s)]++;
		s++;
	}
}

void	count_alpha(char *s)
{
	int	hashtable[127] = {0};
	int	first = 0;

	count_ascii(s, (int*)&hashtable);

	while (*s)
	{
		*s = to_lower(*s);
		if (IS_ALPHA(*s) && hashtable[(int)*s] != USED)
		{
			if (first != 0)
				printf(", ");
			first = 1;
			printf("%d%c", hashtable[(int)*s], *s);
			hashtable[(int)*s] = USED;
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
