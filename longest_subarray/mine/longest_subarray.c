/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 13:46:39 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/10 13:46:40 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define DIGIT(c) (c >= '0' && c <= '9')

/*
**	"As a reminder, 0, 2, 4, 6, 8 are even digits and 1, 3, 5, 7, 9 are odd."
**	but 0 and % causes problems
*/
static int	is_odd(int n)
{
	if (n == 0)
		return (0);
	return (n % 2);
}

static int	get_subarray(char *arr)
{
	int	max = -1;
	int evens = 0;
	int odds = 0;

	for (int i = 0; arr[i]; ++i)
	{
		if (DIGIT(arr[i]))
		{
			if (is_odd(arr[i] - '0'))
				odds++;
			else
				evens++;
		}
		if (odds == evens)
			if (i > max)
				max = i;
	}
	if (max != -1)
		return (max + 1);
	return (max);
}

/*
**	"The function returns a null-terminated array."
*/
static char	*get_substr(char *str, int start, int len)
{
	char *substr;

	substr = malloc(len + 1);
	for (int i = 0; i < len; ++i)
	{
		substr[i] = str[i + start];
	}
	substr[len] = '\0';
	return (substr);
}

char	*longest_subarray(char *arr)
{
	int curr;
	int	max = 0;
	int	max_start = 0;

	for (int i = 0; arr[i]; ++i)
	{
		curr = get_subarray(arr + i);
		if (curr > max)
		{
			max = curr;
			max_start = i;
		}
	}
	return (get_substr(arr, max_start, max));
}