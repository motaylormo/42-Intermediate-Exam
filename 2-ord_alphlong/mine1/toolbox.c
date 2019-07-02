/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:05:55 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 10:44:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A') + 'a');
	return (c);
}

//	strsplits stuff
#define WHITESPACE(c) (c == ' ' || c == '\t')

static int	count_words(char *str)
{
	int	count = 0;
	while (*str)
	{
		while (*str && WHITESPACE(*str))
			str++;
		if (*str && !WHITESPACE(*str))
		{
			count++;
			while (*str && !WHITESPACE(*str))
				str++;
		}
	}
	return (count);
}

static char	*get_word(char **str)
{
	char	*word;
	int		len = 0;

	while (**str && WHITESPACE(**str))
		(*str)++;
	while ((*str)[len] && !WHITESPACE((*str)[len]))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		word[i] = (*str)[i];
	word[len] = '\0';
	(*str) += len;
	return (word);
}

char	**ft_strsplit(char *str)
{
	char	**arr;
	int		wordcount;

	wordcount = count_words(str);
	arr = malloc(sizeof(char*) * (wordcount + 1));
	for (int i = 0; i < wordcount; ++i)
		arr[i] = get_word(&str);
	arr[wordcount] = NULL;
	return (arr);
}
