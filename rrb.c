void	reverse_rotate_b(struct lst **b_list)
{
	struct lst *iter;
	int i  = 0;
	iter = *b_list;
	while(iter -> next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *b_list;
	(*b_list) = iter;
	while(i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
	write(1, "rrb\n", 4);
}