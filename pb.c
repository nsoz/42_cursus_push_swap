void	remove_from_list(struct lst **node)
{
	struct lst *iter;
	iter = *node;
	*node = (*node) -> next;
	free(iter);
}

void push_to_b(struct lst **node_a, struct lst **node_b) 
{
    if (*node_a) 
	{
        struct lst *new_node = (struct lst *)malloc(sizeof(struct lst));
        new_node->data = (*node_a)->data;
        remove_from_list(node_a);
        new_node->next = *node_b;
        *node_b = new_node;
    }
	write(1, "pb\n", 3);
}
