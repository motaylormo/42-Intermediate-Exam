/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:01:18 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 09:22:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The pivot itself is not included in either set.
*/
/*
int	find_pivot(int *arr, int n)
{
	int	left_sum = 0;
	int	right_sum = 0;

	//	Pivot = 0
	//	Sum up 1 thu (n - 1)
	for (int i = 1; i < n; ++i)
		right_sum += arr[i];

	for (int pivot = 0; pivot < n - 1; ++pivot)
	{
		if (left_sum == right_sum)
			return (pivot);
		left_sum += arr[pivot];
		right_sum -= arr[pivot + 1];
	}
	return (-1);
}
*/

int	find_pivot(int *arr, int n)
{
	int	left_sum = 0;
	int	right_sum = 0;

	for (int i = 0; i < n; ++i)
		right_sum += arr[i];

	for (int pivot = 0; pivot < n - 1; ++pivot)
	{
		if (pivot > 0)
			left_sum += arr[pivot - 1];
		right_sum -= arr[pivot];
		if (left_sum == right_sum)
			return (pivot);
	}
	return (-1);
}

