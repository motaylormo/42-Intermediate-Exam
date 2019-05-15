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

/*
**	"nodes with consecutive values in increasing order."
*/
#define CONSEC(a, b)	(a + 1 == b)

static void	send_snake_down(struct s_node *node, int *max, int path)
{
	if (path > *max)
		*max = path;
	if (node->left)
	{
		send_snake_down(node->left, max,
				(CONSEC(node->value, node->left->value)) ? path + 1 : 1);
	}
	if (node->right)
	{
		send_snake_down(node->right, max,
				(CONSEC(node->value, node->right->value)) ? path + 1 : 1);
	}
}

int		longest_sequence(struct s_node *node)
{
	int	max = 0;
	send_snake_down(node, &max, 1);
	return (max);
}
