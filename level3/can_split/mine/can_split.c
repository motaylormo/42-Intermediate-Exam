/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:42:27 by exam              #+#    #+#             */
/*   Updated: 2019/06/25 09:57:08 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

static int	count_nodes(struct s_node *n)
{
	if (!n)
		return (0);
	return (count_nodes(n->left) + count_nodes(n->right) + 1);
}

static void	find_split(struct s_node *n, int half, int *ptr)
{
	if (n)
	{
		if (count_nodes(n) == half)
			*ptr = 1;
		else
		{
			find_split(n->left, half, ptr);
			find_split(n->right, half, ptr);
		}
	}
}

int	can_split(struct s_node *n)
{
	int	n_count;
	n_count = count_nodes(n);
	if (n_count % 2 != 0)
		return (0);
	int	split = 0;
	find_split(n, n_count / 2, &split);
	return (split);
}
