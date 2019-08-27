/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:22:57 by mtaylor           #+#    #+#             */
/*   Updated: 2019/08/26 20:22:58 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXSIZE 1024

typedef struct	s_point {
	int		x;		// x : Width  | x-axis
	int		y;		// y : Height | y-axis
}				t_point;

int		ft_putchar(char c);
char	*ft_strchr(char *str, char c);
void	flood_fill(char **tab, t_point size, t_point begin, char digit);