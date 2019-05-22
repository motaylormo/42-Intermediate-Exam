/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 10:33:46 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/19 10:33:47 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	n-ary tree
**	"->nodes" is a null-terminated array of all the nodes branching off it
*/
struct s_node {
	int				value;
	struct s_node	**nodes;
};

#define UPDATE_MAX(x, max)	if (x > max) max = x

static void	ht_recurse(struct s_node *n, int height, int *max)
{
	if (n)
	{
		UPDATE_MAX(height, *max);
		if (n->nodes)
		{
			for (int i = 0; n->nodes[i]; ++i)
				ht_recurse(n->nodes[i], height + 1, max);
		}
	}
}

/*
**	A tree with a single node will have a height of 0.
**	An empty tree should have height -1;
*/

int		height_tree(struct s_node *root)
{
	int	max = 0;

	if (!root)
		return (-1);
	ht_recurse(root, 0, &max);
	return (max);
}
