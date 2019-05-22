/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:31:57 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/09 12:31:59 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int				value;
	struct s_node	*next;
};

/*
**	1 = looping
**	0 = not looping
*/
int		is_looping(struct s_node *node)
{
	struct s_node	*slow;
	struct s_node	*fast;

	slow = node;
	fast = node;

	while (slow && fast)
	{
		if (!fast->next)
			break;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
