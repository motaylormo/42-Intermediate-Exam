/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:29:09 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 10:10:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"
#define WHITESPACE(c)	(c == ' ' || c == '\t')

static int	count_words(char *str)
{
	int	count = 0;
	while (*str)
	{
		while (WHITESPACE(*str))
			str++;
		if (*str)
		{
			count++;
			while (*str && !WHITESPACE(*str))
				str++;
		}
	}
	return (count);
}

static char	*ft_substr(char *str, int len)
{
	char *s = malloc(len + 1);
	for (int i = 0; i < len; i++)
		s[i] = str[i];
	s[len] = '\0';
	return (s);
}

char	**ft_strsplit(char *str, int *count)
{
	*count = count_words(str);
	if (*count < 1)
		return (0);
	char	**arr = malloc(sizeof(char*) * (*count + 1));
	int		wordlen;

	for (int i = 0; i < *count; i++)
	{
		while (WHITESPACE(*str))
			str++;
		wordlen = 0;
		while (str[wordlen] && !WHITESPACE(str[wordlen]))
			wordlen++;
		arr[i] = ft_substr(str, wordlen);
		str += wordlen;
	}
	arr[*count] = 0;
	return (arr);
}
