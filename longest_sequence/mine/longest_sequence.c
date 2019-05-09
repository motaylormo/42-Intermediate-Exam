/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:03:58 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/06 12:03:59 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
};

static void	send_snake_down(struct s_node *node, int path, int *ptr)
{
	if (path > *ptr)
		*ptr = path;
	if (node->left)
	{
		if (node->left->value == node->value + 1)
			send_snake_down(node->left, path + 1, ptr);
		else
			send_snake_down(node->left, 1, ptr);
	}
	if (node->right)
	{
		if (node->right->value == node->value + 1)
			send_snake_down(node->right, path + 1, ptr);
		else
			send_snake_down(node->right, 1, ptr);
	}
}

int		longest_sequence(struct s_node *node)
{
	int	ptr = 0;
	send_snake_down(node, 1, &ptr);
	return (ptr);
}
