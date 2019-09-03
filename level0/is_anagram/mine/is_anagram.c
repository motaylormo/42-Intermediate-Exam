/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:03:06 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/02 14:03:32 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	fill_hashtable(char *str, int *hash_table)
{
	for (int i = 0; str[i]; ++i)
		hash_table[(int)str[i]]++;
}

/*
**	    anagrams = return 1
**	not anagrams = return 0
*/
int	is_anagram(char *a, char *b)
{
	int a_hash_table[127] = {0};
	int b_hash_table[127] = {0};

	fill_hashtable(a, a_hash_table);
	fill_hashtable(b, b_hash_table);
	for (int i = 32; i < 127; ++i)
	{
		if (a_hash_table[i] != b_hash_table[i])
			return (0);
	}
	return (1);
}
