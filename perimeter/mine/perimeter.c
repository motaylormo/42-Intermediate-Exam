/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:09:40 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/15 13:09:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define	BOTTOM(n)	(!n->left && !n->right)

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void	bottom_nodes(struct s_node *n)
{
	if (n)
	{
		if (BOTTOM(n))
			printf(" %d", n->value);
		else
		{
			bottom_nodes(n->left);
			bottom_nodes(n->right);
		}
	}
}

static void	leftmost_nodes(struct s_node *n)
{
	if (n && !BOTTOM(n))
	{
		printf(" %d", n->value);
		leftmost_nodes(n->left);
	}
}

static void	rightmost_nodes(struct s_node *n)
{
	if (n && !BOTTOM(n))
	{
		rightmost_nodes(n->right);
		printf(" %d", n->value);
	}
}

/*
**	leftmost() & rightmost() can't be bottom nodes,
**								and are not run on the root.
**	But I DO need to protect against double-printing
**								a root that is also a bottom node.
*/
void	perimeter(struct s_node *root)
{
	if (!root)
		return;
	printf("%d", root->value);
	if (!BOTTOM(root))
	{
		leftmost_nodes(root->left);
		bottom_nodes(root);
		rightmost_nodes(root->right);
	}
	printf("\n");
}