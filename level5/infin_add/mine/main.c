/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:48:03 by exam              #+#    #+#             */
/*   Updated: 2019/08/27 10:52:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

int		traysize;

int		*create_tray(int a, int b)
{
	traysize = ((a > b) ? a : b) + 2;
	int *tray = malloc(sizeof(int) * traysize);
	for (int i = 0; i < traysize; i++)
		tray[i] = 0;
	return (tray);
}

void	place_num(int *tray, char *str)
{
	int	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	int len = ft_strlen(str);
	for (int i = 0; i <= len; i++)
		tray[traysize - i] += (str[len - i] - '0') * sign;
}

int		signs_match(int *tray)
{
	int	neg = 0;
	int pos = 0;
	for (int i = 0; i < traysize; i++)
	{
		if (tray[i] > 0)
			pos++;
		if (tray[i] < 0)
			neg++;
	}
	return ((neg == 0) || (pos == 0));
}

int		get_sign(int *tray)
{
	int i = 0;
	while ((i < traysize - 1) && tray[i] == 0)
		i++;
	return ((tray[i] < 0) ? -1 : 1);
}

void	borrowing(int *tray)
{
	int sign = get_sign(tray);

	for (int i = traysize - 1; i > 0; i--)
	{
		if ((sign == 1 && tray[i] < 0) ||
			(sign == -1 && tray[i] > 0))
		{
			tray[i] += (10 * sign);
			tray[i - 1] -= (1 * sign);
		}
	}
}

void	carry_over(int *tray)
{
	int carry = 0;

	for (int i = traysize - 1; i > 0; i--)
	{
		tray[i] += carry;
		carry = tray[i] / 10;
		tray[i] %= 10;
	}
}

void	print_final_num(int *tray)
{
	int sign = get_sign(tray);
	int i = 0;
	while ((i < traysize - 1) && tray[i] == 0)
		i++;
	if (sign == -1)
		ft_putchar('-');
	while (i < traysize)
		ft_putchar((tray[i++] * sign) + '0');
}

void	infin_add(char *a, char *b)
{
	int	*tray = create_tray(ft_strlen(a), ft_strlen(b));

	place_num(tray, a);
	place_num(tray, b);

	while (!(signs_match(tray)))
		borrowing(tray);
	carry_over(tray);

	print_final_num(tray);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		infin_add(argv[1], argv[2]);
	ft_putchar('\n');
}
