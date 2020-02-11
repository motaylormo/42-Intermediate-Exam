struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

static struct s_node *rightmost(struct s_node *n)
{
	if (!n)
		return (0);
	while (n->right)
		n = n->right;
	return (n);
}
static struct s_node *leftmost(struct s_node *n)
{
	if (!n)
		return (0);
	while (n->left)
		n = n->left;
	return (n);
}

static void	link_up(struct s_node *lefthand, struct s_node *righthand)
{
	if (lefthand)
		lefthand->right = righthand;
	if (righthand)
		righthand->left = lefthand;
}

static struct s_node *	recur(struct s_node *n)
{
	if (!n)
		return (0);

	link_up(rightmost(recur(n->left)), n);
	link_up(n, leftmost(recur(n->right)));

	return (n);
}

struct s_node	*convert_bst(struct s_node *bst_root)
{
	recur(bst_root);

	struct s_node *list = leftmost(bst_root);
	link_up(rightmost(list), list);

	return (list);
}