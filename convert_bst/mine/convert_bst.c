/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:22:18 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/10 12:22:19 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

/*
**	Remove a leaf from the bottom of a tree.
*/
static struct s_node	*remove_leaf(struct s_node *tree)
{
	struct s_node	*n = tree;
	struct s_node	*prev = 0;

	if (!tree)
		return (0);

	while (n->left || n->right)
	{
		prev = n;
		n = (n->left) ? n->left : n->right;
	}
	if (prev)
	{
		if (n == prev->left)
			prev->left = 0;
		if (n == prev->right)
			prev->right = 0;
	}
	return (n);
}

/*
**	insert a node between list_left and list_right
*/
static void	insert_node(struct s_node *list_left,
						struct s_node *list_right, struct s_node *n)
{
	if (list_left)
		list_left->right = n;
	if (list_right)
		list_right->left = n;
	n->left = list_left;
	n->right = list_right;
}

static struct s_node	*add_to_list(struct s_node *list, struct s_node *n)
{
	struct s_node	*head = list;

	if (!list)
	{
		list = n;
		return (list);
	}
	else if (n->value <= list->value)
	{
		insert_node(list->left, list, n);
		return (list->left);
	}
	else if (n->value > list->value)
	{
		head = list;
		while (list->right && (n->value > list->right->value))
			list = list->right;
		insert_node(list, list->right, n);
		return (head);
	}
	return (list);
}

static struct s_node	*link_list(struct s_node *head)
{
	struct s_node	*end;

	end = head;
	while (end->right)
		end = end->right;

	end->right = head;
	head->left = end;
	return (head);
}

struct s_node	*convert_bst(struct s_node *bst)
{
	struct s_node	*list = 0;
	struct s_node	*n = 0;

	while (n != bst)//ends when the node (leftover from list time) is the root of the tree
	{
		n = remove_leaf(bst);
		if (n == 0)
			break;
		list = add_to_list(list, n);
	}
	return (link_list(list));
}
