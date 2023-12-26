void	reverse_rotate_a(struct lst **a_list)
{
	struct lst *iter;
	int i  = 0;
	iter = *a_list;
	while(iter -> next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *a_list;
	(*a_list) = iter;
	while(i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
	write(1 "rra\n", 4);
}