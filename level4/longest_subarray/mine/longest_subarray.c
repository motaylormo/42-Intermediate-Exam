/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:40:59 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:55:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	"The function returns a null-terminated array."
*/
static char	*ft_substr(char *str, int len)
{
	char *s = malloc(len + 1);
	for (int i = 0; i < len; i++)
		s[i] = str[i];
	s[len] = '\0';
	return (s);
}

static int	find_subarr_len(char *str)
{
	int	odds = 0;
	int evens = 0;
	int	max = 0;

	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break;
		if ((str[i] - '0') % 2 == 1)
			odds++;
		else
			evens++;
		if (odds == evens)
			max = i + 1;
	}
	return (max);
}

char	*longest_subarray(char *str)
{
	int	max = 0;
	int	max_i;

	for (int i = 0; str[i]; i++)
	{
		int curr = find_subarr_len(str + i);
		if (curr > max)
		{
			max = curr;
			max_i = i;
		}
	}
	return (ft_substr(str + max_i, max));
}
