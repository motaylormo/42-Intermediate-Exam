/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:46:47 by exam              #+#    #+#             */
/*   Updated: 2019/05/07 09:47:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void			*content;
	struct s_node	*next;
};

struct s_stack {
	struct s_node	*top;
};

/*
**	Initialize the stack.
**	The top pointer is set to NULL.
*/
struct s_stack *init(void)
{
	struct s_stack	*s;

	s = malloc(sizeof(struct s_stack));
	s->top = NULL;
	return (s);
}

/*
**	Return 1 if the stack is empty, 0 otherwise.
*/
int		isEmpty(struct s_stack *s)
{
	if (s->top == NULL)
		return (1);
	else
		return (0);
}

/*
**	Remove the top item from the stack and return it. [aka return top's content]
**	If the stack is empty, the function returns NULL.
*/
void	*pop(struct s_stack *s)
{
	struct s_node	*n;
	void			*to_return;

	if (isEmpty(s))
		return (NULL);
	n = s->top;
	s->top = s->top->next;

	to_return = n->content;
	n->next = NULL;
	free(n);
	return (to_return);
}

/*
**	Add an item to the top of the stack.
*/
void	push(struct s_stack *s, void *content)
{
	struct s_node	*n;

	n = malloc(sizeof(n));
	n->content = content;
	n->next = s->top;
	s->top = n;
}

/*
**	Return the top of the stack. [aka return top's content]
**	If the stack is empty, the function returns NULL.
*/
void	*peek(struct s_stack *s)
{
	if (isEmpty(s))
		return (NULL);
	return (s->top->content);
}
