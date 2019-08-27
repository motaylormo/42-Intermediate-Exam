/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:24:10 by exam              #+#    #+#             */
/*   Updated: 2019/08/27 09:29:05 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void	reverse_tree(struct s_node *n)
{
	struct s_node *tmp;

	if (n)
	{
		tmp = n->left;
		n->left = n->right;
		n->right = tmp;
		reverse_tree(n->left);
		reverse_tree(n->right);
	}
}
