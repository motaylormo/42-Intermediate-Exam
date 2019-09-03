/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:58:14 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/12 13:58:16 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*other;
};

static int	list_len(struct s_node *n)
{
	int	count = 0;
	while (n)
	{
		count++;
		n = n->next;
	}
	return (count);
}

static struct s_node	*create_node(int value)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->data = value;
	n->next = NULL;
	n->other = NULL;
	return (n);
}

/*
**	Duplicates the list for "data" and "next".
**	"Other" is always NULL.
*/
static struct s_node	*simple_dupe(struct s_node *orig)
{
	struct s_node	*clone_head = NULL;
	struct s_node	*clone = NULL;

	while (orig)
	{
		if (!clone_head)
		{
			clone = create_node(orig->data);
			clone_head = clone;
		}
		else
		{
			clone->next = create_node(orig->data);
			clone = clone->next;
		}
		orig = orig->next;
	}
	return (clone_head);
}

/*
**	"Other... points to any node in the list (another node, itself or NULL)."
*/
static void		handle_other(struct s_node *orig_head,
							struct s_node *clone_head, int len)
{
	struct s_node	*orig_arr[len];
	struct s_node	*clone_arr[len];
	struct s_node	*orig = orig_head;
	struct s_node	*clone = clone_head;
	int	s;

	for (int i = 0; i < len; ++i)
	{
		orig_arr[i] = orig;
		clone_arr[i] = clone;
		orig = orig->next;
		clone = clone->next;
	}
	orig = orig_head;
	clone = clone_head;
	for (int i = 0; i < len; ++i)
	{
		if (orig->other != NULL)
		{
			s = 0;
			while ((s < len) && (orig->other != orig_arr[s]))
				s++;
			clone->other = clone_arr[s];
		}
		orig = orig->next;
		clone = clone->next;
	}
}

/*
**	"Write a function to create a copy of this list (allocate new memory).
**	You cannot modify the structure, you cannot modify the list you are given."
*/
struct s_node	*clone_list(struct s_node *orig)
{
	int				len;
	struct s_node	*clone;

	len = list_len(orig);
	clone = simple_dupe(orig);
	handle_other(orig, clone, len);
	return (clone);
}