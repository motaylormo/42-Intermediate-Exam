/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:47:59 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/12 13:48:00 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void	rt_recurse(struct s_node *n)
{
	struct s_node	*tmp;

	if (n && (n->left || n->right))
	{
		tmp = n->left;
		n->left = n->right;
		n->right = tmp;
		rt_recurse(n->left);
		rt_recurse(n->right);
	}
}

void	reverse_tree(struct s_node *root)
{
	if (root)
		rt_recurse(root);
}