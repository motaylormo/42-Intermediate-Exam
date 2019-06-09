/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:58:14 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/08 18:58:15 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord_alphlong.h"

#define WHITESPACE(c) (c == '\t' || c == ' ')

static int	count_words(char *str)
{
	int	tally = 0;
	while (*str)
	{
		while (*str && WHITESPACE(*str))
			str++;
		while (*str && !WHITESPACE(*str))
			str++;
		tally++;
	}
	return (tally);
}

static char	*get_word(char *str)
{
	char	*word;
	int		len = 0;

	while (*str && WHITESPACE(*str))
		str++;
	while (str[len] && !WHITESPACE(str[len]))
		len++;
	word = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		word[i] = str[i];
	word[len] = '\0';
	return (word);
}

char	**ft_strsplit(char *str)
{
	int		word_count = count_words(str);
	char	**meta_array;

	meta_array = (char**)malloc(sizeof(char*) * (word_count + 1));
	for (int i = 0; i < word_count; i++)
	{
		meta_array[i] = get_word(str);
		while (*str && WHITESPACE(*str))
			str++;
		while (*str && !WHITESPACE(*str))
			str++;
		while (*str && WHITESPACE(*str))
			str++;
	}
	meta_array[word_count] = NULL;
	return (meta_array);
}

