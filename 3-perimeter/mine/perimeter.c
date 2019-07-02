/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:27:00 by mtaylor           #+#    #+#             */
/*   Updated: 2019/07/02 14:27:01 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#define	LEAF(n)	(!n->left && !n->right)

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

static void	leaf_nodes(struct s_node *n)
{
	if (n)
	{
		if (LEAF(n))
			printf(" %d", n->value);
		else
		{
			leaf_nodes(n->left);
			leaf_nodes(n->right);
		}
	}
}

static void	leftmost_nodes(struct s_node *n)
{
	if (n && !LEAF(n))
	{
		printf(" %d", n->value);
		leftmost_nodes(n->left);
	}
}

static void	rightmost_nodes(struct s_node *n)
{
	if (n && !LEAF(n))
	{
		rightmost_nodes(n->right);
		printf(" %d", n->value);
	}
}

/*
**	leftmost() & rightmost() can't be leaf nodes,
**		and are not run on the root.
**	But I DO need to protect against double-printing
**		root that is also a leaf node.
*/
void	perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		if (!LEAF(root))
		{
			leftmost_nodes(root->left);
			leaf_nodes(root);
			rightmost_nodes(root->right);
		}
		printf("\n");
	}
}
