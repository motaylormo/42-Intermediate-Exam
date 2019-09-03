/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:33:15 by exam              #+#    #+#             */
/*   Updated: 2019/07/02 11:33:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	void			*content;
	struct s_node	*next;
};

void	*intersection(struct s_node *lst1, struct s_node *lst2)
{
	for (struct s_node *k = lst1; k; (k = k->next))
	{
		for (struct s_node *j = lst2; j; (j = j->next))
		{
			if (k == j)
				return (k);
		}
	}
	return (0);
}