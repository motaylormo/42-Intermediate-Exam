/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:57:56 by mtaylor           #+#    #+#             */
/*   Updated: 2019/05/09 11:57:58 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_queue {
	struct s_node	*first;
	struct s_node	*last;
};

/*
**	Initialize the queue.
**	The first and last pointers are set to NULL.
*/
struct s_queue	*init(void)
{
	struct s_queue	*q;

	q = malloc(sizeof(struct s_queue));
	q->first = NULL;
	q->last = NULL;
	return (q);
}

/*
**	Add an item to the end of the queue.
*/
void			enqueue(struct s_queue *q, void *content)
{
	struct s_node	*n;

	n = malloc(sizeof(struct s_node));
	n->content = content;
	n->next = NULL;
	if (q->first == NULL)
	{
		q->first = n;
		q->last = n;
	}
	else
	{
		q->last->next = n;
		q->last = n;
	}
}

/*
**	Remove the first item from the queue and return it.
**	If the queue is empty, the function returns NULL.
*/
void			*dequeue(struct s_queue *q)
{
	struct s_node	*to_free;
	void			*to_return;

	if (!q || !q->first)
		return (NULL);

	to_free = q->first;
	to_return = to_free->content;
	if (to_free == q->last)
	{
		q->first = NULL;
		q->last = NULL;
	}
	else
		q->first = q->first->next;
	free(to_free);
	return (to_return);
}

/*
**	Return the first item of the queue.
**	If the queue is empty, the function returns NULL.
*/
void			*peek(struct s_queue *q)
{
	if (!q || !q->first)
		return (NULL);
	return (q->first->content);
}

/*
**	Return 1 if the queue is empty, 0 otherwise.
*/
int				isEmpty(struct s_queue *q)
{
	if (q->first)
		return (0);
	else
		return (1);
}
