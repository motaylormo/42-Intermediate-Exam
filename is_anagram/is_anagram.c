/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:01:06 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 10:01:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ascii_of_str(char *str, int table[127])
{
	while (*str)
	{
		table[(int)*str]++;
		str++;
	}
}

/*
**	    anagrams = return 1
**	not anagrams = return 0
*/
int	is_anagram(char *a, char *b)
{
	int a_ascii[127] = {0};
	int b_ascii[127] = {0};

	ascii_of_str(a, a_ascii);
	ascii_of_str(b, b_ascii);
	for (int i = 32; i < 127; ++i)
	{
		if (a_ascii[i] != b_ascii[i])
			return (0);
	}
	return (1);
}
