/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:35:26 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/19 11:35:27 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

#define IN_BOUNDS(i, size)		((i >= 0) && (i < size))
#define EXISTS(i, j, is, js)	(IN_BOUNDS(i, is) && IN_BOUNDS(j, js))

#define	IS_NEG(s)		(s[0] == '-')
#define ZERO_CHECK(s)	(s[0] == '0' && s[1] == '\0')

void	handle_signs(char **a, char **b)
{
	if (IS_NEG(*a) != IS_NEG(*b))
		ft_putchar('-');
	if (*a[0] == '-')
		(*a)++;
	if (*b[0] == '-')
		(*b)++;
}

int		**lattice_matrix(char *a, char *b, int a_len, int b_len)
{
	int	**arr;

	arr = malloc(sizeof(int*) * a_len);
	for (int i = 0; i < a_len; ++i)
	{
		arr[i] = malloc(sizeof(int) * b_len);
		for (int j = 0; j < b_len; ++j)
		{
			arr[i][j] = (a[i] - '0') * (b[j] - '0');
		}
	}
	return (arr);
}

int		run_row(int **arr, int row, int col, int row_len, int col_len)
{
	int sum = 0;
	while (EXISTS(row, col, row_len, col_len))
	{
		sum += arr[row][col];
		row++;
		col--;
	}
	return (sum);
}

int		*lattice_solve(int **arr, int row_len, int col_len)
{
	int	*sum;
	int	s;
	int	row = row_len - 1;
	int	col = col_len - 1;

	sum = malloc(sizeof(int) * (row_len + col_len + 1));
	s = row_len + col_len;
	while (row >= 0 && col >= 0)
	{
		sum[s--] = run_row(arr, row, col, row_len, col_len);
		if (row > 0)
			row--;
		else
			col--;
	}
	while (s >= 0)
		sum[s--] = 0;
	return (sum);
}

int		*carrying_over(int *sum, int arr_size)
{
	int over = 0;
	for (int i = arr_size; i >= 0; --i)
	{
		sum[i] += over;
		over = sum[i] / 10;
		sum[i] = (sum[i] == 0) ? 0 : sum[i] % 10;
	}
	return (sum);
}

void	infin_mult(char *a, char *b)
{
	if (ZERO_CHECK(a) || ZERO_CHECK(b))
		return (ft_putchar('0'));

	int	a_len;
	int	b_len;
	int	**lattice;
	int	*sum;

	handle_signs(&a, &b);
	a_len = ft_strlen(a);
	b_len = ft_strlen(b);
	lattice = lattice_matrix(a, b, a_len, b_len);
	sum = lattice_solve(lattice, a_len, b_len);
	sum = carrying_over(sum, a_len + b_len);

	int i = 0;
	while ((i < a_len + b_len) && (sum[i] == 0))
		i++;
	while (i <= a_len + b_len)
		ft_putchar(sum[i++] + '0');
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		infin_mult(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}