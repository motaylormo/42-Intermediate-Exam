/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:54:44 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 12:01:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

#define POINT_EXISTS(x, y, map)	(x >= 0 && y >= 0 && map[x] && map[x][y])

void	flood_fill(char **map, int x, int y, char c)
{
	if (POINT_EXISTS(x, y, map) && (map[x][y] == 'X'))
	{
		map[x][y] = c;
		flood_fill(map, x + 1, y, c);
		flood_fill(map, x - 1, y, c);
		flood_fill(map, x, y + 1, c);
		flood_fill(map, x, y - 1, c);
	}
}
