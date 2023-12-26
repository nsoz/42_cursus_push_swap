void	remove_from_list(struct lst **node)
{
	struct lst *iter;
	iter = *node;
	*node = (*node) -> next;
	free(iter);
}


void push_to_a(struct lst **node_a, struct lst **node_b) 
{
    if (*node_b) 
	{
        struct lst *new_node = (struct lst *)malloc(sizeof(struct lst));
        new_node->data = (*node_b)->data;
        remove_from_list(node_b);
        new_node->next = *node_a;
        *node_a = new_node;
    }
	write(1, "pa\n", 3);
}
