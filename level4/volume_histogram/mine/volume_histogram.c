/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 12:20:32 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/30 12:20:33 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SMALLER(a, b) ((a < b) ? a : b)

/*
**	Find the next levee that is >= the first levee.
**	If there are no >= ones left, then the biggest levee remaining.
*/
static int	get_next_levee(int *arr, int size, int levee1)
{
	int backup = size - 1;

	for (int i = levee1 + 1; i < size; ++i)
	{
		if (arr[i] >= arr[levee1])
			return (i);
		if (arr[i] >= arr[backup])
			backup = i;
	}
	return (backup);
}

static int	get_block_vol(int *arr, int levee1, int levee2)
{
	int	vol = SMALLER(arr[levee1], arr[levee2])
				* (levee2 - levee1 - 1);

//displaced water
	for (int i = levee1 + 1; i < levee2; i++)
	{
		vol -= arr[i];
	}
	return (vol);
}

int		volume_histogram(int *histogram, int size)
{
	int sum = 0;
	int levee1 = 0;
	int levee2;
	while (levee1 < (size - 1))
	{
		levee2 = get_next_levee(histogram, size, levee1);
		sum += get_block_vol(histogram, levee1, levee2);
		levee1 = levee2;
	}
	return (sum);
}
