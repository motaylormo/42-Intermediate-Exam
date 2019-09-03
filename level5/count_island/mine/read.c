/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:59:15 by exam              #+#    #+#             */
/*   Updated: 2019/09/03 12:07:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

static char	*ft_strdup(char *src, int len)
{
	char *dup = malloc(len + 1);
	for (int i = 0; i < len; i++)
		dup[i] = src[i];
	dup[len] = '\0';
	return (dup);
}

static int	valid_chars(char *str, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (!(str[i] == '.' || str[i] == 'X'))
			return (0);
	}
	return (1);
}

static char	*get_first_line(int fd, int *len)
{
	char	buf[1024];

	*len = 0;
	while (read(fd, buf + *len, 1))
	{
		if (buf[*len] == '\n')
		{
			if (valid_chars(buf, *len))
				return (ft_strdup(buf, *len));
			else
				return (0);
		}
		(*len)++;
	}
	return (0);
}

char	**read_in_file(int fd)
{
	char	**arr = malloc(sizeof(char*) * 1024);
	int		len;
	char	buf[1024];
	int		i = 0;

	if (!(arr[i++] = get_first_line(fd, &len)))
		return (0);
	while (read(fd, buf, len + 1) == len + 1)
	{
		if (buf[len] == '\n' && valid_chars(buf, len))
			arr[i++] = ft_strdup(buf, len);
		else
			return (0);
	}
	arr[i] = 0;
	return (arr);
}
