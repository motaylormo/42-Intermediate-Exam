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
**	Returns 1 if the linked list is looping, otherwise 0.
*/
int		is_looping(struct s_node *node)
{
	struct s_node	*slow;
	struct s_node	*fast;

	slow = node;
	fast = node;

	while (slow && fast)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}