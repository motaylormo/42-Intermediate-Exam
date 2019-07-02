/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:41:16 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 11:41:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strequ(char *a, char *b)
{
	for (int i = 0; a[i] || b[i]; ++i)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}