/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 10:02:39 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 10:02:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void	reverse_tree_recurse(struct s_node *n)
{
	struct s_node	*tmp;

	if (!n)
		return ;
	if (n->left || n->right)
	{
		tmp = n->left;
		n->left = n->right;
		n->right = tmp;
		if (n->left)
			reverse_tree_recurse(n->left);
		if (n->right)
			reverse_tree_recurse(n->right);
	}
}

void	reverse_tree(struct s_node *root)
{
	if (root)
		reverse_tree_recurse(root);
}
