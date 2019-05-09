/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:01:06 by exam              #+#    #+#             */
/*   Updated: 2019/04/23 10:01:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

#define	UPPER_BOUND(p, size)	((p.x < size.x) && (p.y < size.y))
#define	LOWER_BOUND(p)			((p.x >= 0) && (p.y >= 0))
#define	POINT_EXISTS(p, size)	(UPPER_BOUND(p, size) && LOWER_BOUND(p))

static void	ff_recurse(char **tab, t_point size, char match, t_point p)
{
	if (POINT_EXISTS(p, size) && (tab[p.y][p.x] == match))
	{
		tab[p.y][p.x] = 'F';
		ff_recurse(tab, size, match, (t_point){p.x + 1, p.y});
		ff_recurse(tab, size, match, (t_point){p.x, p.y + 1});
		ff_recurse(tab, size, match, (t_point){p.x - 1, p.y});
		ff_recurse(tab, size, match, (t_point){p.x, p.y - 1});
	}
}

void		flood_fill(char **tab, t_point size, t_point begin)
{
	char	match;

	if (POINT_EXISTS(begin, size))
	{
		match = tab[begin.y][begin.x];
		ff_recurse(tab, size, match, begin);
	}
}