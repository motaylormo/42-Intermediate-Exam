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
*/
static int	next_bigger(int *histogram, int size, int i)
{
	int	levee1 = histogram[i];
	int	tmp_i = -1;
	int	tmp_size = 0;

	while (++i < size)
	{
		if (histogram[i] >= levee1)
			return (i);
		if (histogram[i] > tmp_size)
		{
			tmp_size = histogram[i];
			tmp_i = i;
		}
	}
	return (tmp_i);
}

/*
**	Find the volumn between the two levees
**		then remove any smaller walls inside that (displacement)
*/
static int	get_block(int *histogram, int start, int end)
{
	int	vol;

	vol = SMALLER(histogram[start], histogram[end]) * (end - start - 1);

	for (int i = start + 1; i < end; ++i)
	{
		vol -= histogram[i];//displacement
	}
	return ((vol > 0) ? vol : 0);
}

int		volume_histogram(int *histogram, int size)
{
	int	total_vol = 0;
	int	i = 0;
	int	next;

	while (i < size)
	{
		next = next_bigger(histogram, size, i);
		if (next == -1)
			break;
		total_vol += get_block(histogram, i, next);
		i = next;
	}
	return (total_vol);
}
