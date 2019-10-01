#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

static struct s_node	*fresh_node(int val)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->data = val;
	node->next = 0;
	node->other = 0;
	return (node);
}

static struct s_node	*add_to_list(struct s_node *list, struct s_node *node)
{
	if (!list)
		return (node);
	while (list->next)
		list = list->next;
	list->next = node;
	return (node);
}

static void		*get_matching_index(struct s_node *orig, struct s_node *ptr,
									struct s_node *clone)
{
	while (orig && clone)
	{
		if (orig == ptr)
			return (clone);
		orig = orig->next;
		clone = clone->next;
	}
	return (0);
}

struct s_node	*clone_list(struct s_node *orig_head)
{
	struct s_node	*clone_head = 0;
	struct s_node	*clone = 0;

	for (struct s_node *orig = orig_head; orig; orig = orig->next)
	{
		clone = add_to_list(clone, fresh_node(orig->data));
		if (!clone_head)
			clone_head = clone;
	}

	clone = clone_head;
	for (struct s_node *orig = orig_head; orig; orig = orig->next)
	{
		if (orig->other)
			clone->other = get_matching_index(orig_head, orig->other, clone_head);
		clone = clone->next;
	}
	return (clone_head);
}