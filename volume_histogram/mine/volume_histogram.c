/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:17:27 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/15 13:17:29 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SMALLER(a, b)	((a <= b) ? a : b)

/*
**	Find the next levee that is >= the first levee
**		of (if there are no >= levees left) the biggest levee left
*/
static int	next_levee(int *arr, int size, int i)
{
	int	levee1 = arr[i];
	int	backup;

	backup = i + 1;
	while (++i < size)
	{
		if (arr[i] >= levee1)
			return (i);
		if (arr[i] > arr[backup])
			backup = i;
	}
	return ((backup < size) ? backup : size);
}

/*
**	Find the volumn between the two levees
**		then remove any smaller walls inside (displaced water)
*/
static int	get_block(int *arr, int levee1, int levee2)
{
	int	vol;

	vol = SMALLER(arr[levee1], arr[levee2]) * (levee2 - levee1 - 1);

	for (int i = levee1 + 1; i < levee2; ++i)
	{
		vol -= arr[i];
	}
	return ((vol > 0) ? vol : 0);
}

int		volume_histogram(int *arr, int size)
{
	int	total_vol = 0;
	int	i = 0;
	int	next;

	while (i < size)
	{
		next = next_levee(arr, size, i);
		total_vol += get_block(arr, i, next);
		i = next;
	}
	return (total_vol);
}
