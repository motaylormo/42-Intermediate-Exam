/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:42:41 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/12 13:42:42 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

#define	IN_BOUNDS(x, n) ((x >= 0) && (x < n))
#define	POINT_EXISTS(p, size) (IN_BOUNDS(p.x, size.x) && IN_BOUNDS(p.y, size.y))

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