/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 09:10:07 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 09:10:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define LOWERCASE(c) ((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c)

void	fill_hashtable(char *str, int *hash_table)
{
	for (int i = 0; str[i]; ++i)
	{
		if (ALPHA(str[i]))
			hash_table[(int)LOWERCASE(str[i])]++;
	}
}

void	count_alpha(char *str)
{
	int	hash_table[127] = {0};
	int	first = 1;

	fill_hashtable(str, hash_table);
	for (int i = 0; str[i]; ++i)
	{
		if (ALPHA(str[i]) && hash_table[LOWERCASE(str[i])] > 0)
		{
			if (first == 0)
				printf(", ");
			else
				first = 0;
			printf("%d%c", hash_table[LOWERCASE(str[i])], LOWERCASE(str[i]));
			hash_table[LOWERCASE(str[i])] = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		count_alpha(argv[1]);
	printf("\n");
	return (0);
}