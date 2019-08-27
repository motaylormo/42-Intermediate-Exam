/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:48:30 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/26 20:48:31 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

//	Flood fill
#define	IN_BOUNDS(x, n) ((x >= 0) && (x < n))
#define	POINT_EXISTS(p, size) (IN_BOUNDS(p.x, size.x) && IN_BOUNDS(p.y, size.y))

static void	ff_recurse(char **tab, t_point size, char digit, t_point p)
{
	if (POINT_EXISTS(p, size) && (tab[p.y][p.x] == 'X'))
	{
		tab[p.y][p.x] = digit;
		ff_recurse(tab, size, digit, (t_point){p.x + 1, p.y});
		ff_recurse(tab, size, digit, (t_point){p.x, p.y + 1});
		ff_recurse(tab, size, digit, (t_point){p.x - 1, p.y});
		ff_recurse(tab, size, digit, (t_point){p.x, p.y - 1});
	}
}

void		flood_fill(char **tab, t_point size, t_point begin, char digit)
{
	if (POINT_EXISTS(begin, size) &&
		(tab[begin.y][begin.x] == 'X'))
	{
		ff_recurse(tab, size, digit, begin);
	}
}