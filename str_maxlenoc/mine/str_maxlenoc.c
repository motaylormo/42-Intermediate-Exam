/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:08:33 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/19 11:08:34 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allowed functions: write, malloc, free
*/
#include <stdlib.h>
#include <unistd.h>

static void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

static char	*ft_strndup(char *old, int n)
{
	char *new;

	new = malloc(n + 1);
	for (int i = 0; i < n; i++)
		new[i] = old[i];
	new[n] = '\0';
	return (new);
}

/*
**	Important that it's ">", not ">=" !!
**		"If more that one string qualifies,
**		display the one that appears first in the first parameter"
*/
static int	check_match(char *a, char *b, int prev_len)
{
	int	i = 0;
	while (a[i] && b[i] && (a[i] == b[i]))
		i++;
	return ((i > prev_len) ? i : 0);
}

/*
**	if (match == NULL) return ""
**		"Note that the empty string technically appears in any string."
*/
static char	*find_overlap(char *a, char *b)
{
	char	*match = NULL;
	int		match_len = 0;
	int		new_len;

	for (int ai = 0; a[ai]; ai++)
	{
		for (int bi = 0; b[bi]; bi++)
		{
			if ((new_len = check_match(a + ai, b + bi, match_len)))
			{
				if (match)
					free(match);
				match = ft_strndup(a + ai, new_len);
				match_len = new_len;
			}
		}
	}
	return ((match == NULL) ? "" : match);
}

/*
**	Remember that 1 parameter = print out that 1 parameter in full.
*/
int		main(int argc, char **argv)
{
	char	*overlap = NULL;

	if (argc >= 2)
	{
		overlap = argv[1];
		for (int i = 2; i < argc; i++)
			overlap = find_overlap(overlap, argv[i]);
		ft_putstr(overlap);
	}
	ft_putstr("\n");
}
