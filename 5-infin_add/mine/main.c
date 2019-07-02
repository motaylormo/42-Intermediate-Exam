/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:41:23 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 11:41:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

#define DIGIT(c) (c >= '0' && c <= '9')

int a_sign = 1;
int b_sign = 1;

static int	get_digit(char *str)
{
	if (!*str || !DIGIT(*str))
		return (0);
	int	index = ft_strlen(str) - 1;
	int digit = str[index] - '0';
	str[index] = '\0';
	return (digit);
}

void	recurse_add(char *a, char *b, int carry)
{
	int sum = (get_digit(a) * a_sign)
			+ (get_digit(b) * b_sign) + carry;

	if (!*a && !*b && (sum > -10 && sum < 0))
	{
		ft_putchar('-');
		if (sum != 0)
			ft_putchar('0' + (-sum));
		return;
	}

	carry = sum / 10;
	int digit = sum % 10;
	while (digit < 0)
	{
		carry -= 1;
		digit += 10;
	}
	if (*a || *b || carry != 0)
		recurse_add(a, b, carry);
	ft_putchar('0' + digit);
}

void	infin_add(char *a, char *b)
{
	if (a[0] != '-' && b[0] != '-')
		recurse_add(a, b, 0);
	else if (a[0] == '-' && b[0] == '-')
	{
		ft_putchar('-');
		recurse_add(a + 1, b + 1, 0);
	}
	else
	{
		if (a[0] == '-')
		{
			a_sign = -1;
			recurse_add(a + 1, b, 0);
		}
		else
		{
			b_sign = -1;
			recurse_add(a, b + 1, 0);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		infin_add(argv[1], argv[2]);
	ft_putchar('\n');
}
