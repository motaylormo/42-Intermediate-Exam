/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:29:48 by exam              #+#    #+#             */
/*   Updated: 2019/08/20 11:29:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"
#define LARGER(a, b)	((a > b) ? a : b)
//int	traysize;

int		signs_match(int *tray, int traysize)
{
	int minuses = 0;
	int pluses = 0;
	for (int i = 0; i < traysize; i++)
	{
		if (tray[i] > 0)
			pluses++;
		if (tray[i] < 0)
			minuses++;
	}
	return (minuses == 0 || pluses == 0);
}

int		*setup_tray(int traysize)
{
	int *tray = malloc(sizeof(int) * traysize);
	for (int i = 0; i < traysize; i++)
		tray[i] = 0;
	return (tray);
}

void	place_num(int *tray, int traysize, char *str)
{
	int sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	int len = ft_strlen(str);
	for (int i = 1; i <= len; i++)
	{
		tray[traysize - i] += (str[len - i] - '0') * sign;
	}
}

void	placerounding(int *tray, int traysize)
{
	for (int i = traysize - 1; i > 0; i--)
	{
		if (tray[i] >= 10 || tray[i] <= -10)
		{
			tray[i - 1] += tray[i] / 10;
			tray[i] %= 10;
		}
	}
}

void	borrowing(int *tray, int traysize)
{
	while (!signs_match(tray, traysize))
	{
		for (int i = traysize - 1; i > 0; i--)
		{
			if (tray[i] < 0)
			{
				tray[i - 1] -= 1;
				tray[i] += 10;
			}
		}
	}
}

void	print_num(int *tray, int traysize)
{
	int i = 0;
	while (tray[i] == 0 && (i + 1 < traysize))
		i++;

	int sign = (tray[i] < 0) ? -1 : 1;
	if (sign == -1)
		ft_putchar('-');
	while (i < traysize)
	{
		ft_putchar((tray[i] * sign) + '0');
		i++;
	}
}

void	infin_add(char *a, char *b)
{
	int traysize = 2 + LARGER(ft_strlen(a), ft_strlen(b));
	int *tray = setup_tray(traysize);
	place_num(tray, traysize, a);
	place_num(tray, traysize, b);

	borrowing(tray, traysize);
	placerounding(tray, traysize);

	print_num(tray, traysize);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		infin_add(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
