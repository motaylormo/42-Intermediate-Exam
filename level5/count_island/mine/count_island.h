/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:57:14 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 11:59:41 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>//open
#include <unistd.h>//close, read, write
#include <stdlib.h>//malloc, free

char	**read_in_file(int fd);
void	flood_fill(char **map, int x, int y, char c);
