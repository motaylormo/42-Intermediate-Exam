/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:48:05 by mtaylor           #+#    #+#             */
/*   Updated: 2019/09/16 17:48:10 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void	link_2_nodes(struct s_node *a, struct s_node *b)
{
	a->left = b;
	b->right = a;
}

static void	convert_subtree(struct s_node *curr, struct s_node **prev)
{
	if (curr == 0)
		return;

	convert_subtree(curr->left, prev);
	if (*prev)
		link_2_nodes(curr, *prev);
	*prev = curr;
	convert_subtree(curr->right, prev);
}

static struct s_node	*link_ends(struct s_node *curr)
{
	struct s_node *leftmost = curr;
	struct s_node *rightmost = curr;
	while (leftmost->left)
		leftmost = leftmost->left;
	while (rightmost->right)
		rightmost = rightmost->right;
	link_2_nodes(leftmost, rightmost);
	return (leftmost);
}

struct s_node	*convert_bst(struct s_node *bst)
{
	if (bst == 0)
		return (0);

	struct s_node *prev = 0;
	convert_subtree(bst, &prev);
	return (link_ends(bst));
}
