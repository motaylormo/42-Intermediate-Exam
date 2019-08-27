/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:26:03 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 09:26:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

/*
**	strsplit stuff
*/
#define WHITESPACE(c)	(c == ' ' || c == '\t')

static int	count_words(char *str)
{
	int	tally = 0;
	while (*str)
	{
		while (WHITESPACE(*str))
			str++;
		if (*str && !WHITESPACE(*str))
		{
			tally++;
			while (*str && !WHITESPACE(*str))
				str++;
		}
	}
	return (tally);
}

static char	*ft_substr(char *src, int len)
{
	char *str;

	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	for (int i = 0; i < len; ++i)
		str[i] = src[i];
	return (str);
}

char	**ft_strsplit(char *str)
{
	int	word_count = count_words(str);
	char **arr;

	arr = malloc(sizeof(char*) * (word_count + 1));
	arr[word_count] = NULL;
	int i = 0;
	while (i < word_count)
	{
		while (WHITESPACE(*str))
			str++;
		if (*str && !WHITESPACE(*str))
		{
			int len = 0;
			while (str[len] && !WHITESPACE(str[len]))
				len++;
			arr[i++] = ft_substr(str, len);
			str += len;
		}
	}
	return (arr);
}