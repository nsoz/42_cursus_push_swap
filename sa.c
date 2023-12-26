void	swap_a(struct lst *node)
{
	if (node -> next !=NULL)
	{	
		int tmp;
		tmp = node -> data;
		node -> data = node->next->data;
		node -> next -> data = tmp;
	}
	write(1, "sa\n", 3);
}
