
void	rotate_a(struct lst **list)
{
	struct lst *iter;
	struct lst *holder;
	iter = *list;
	*list = (*list) -> next;
	holder = *list;
	while(holder -> next != NULL)
		holder = holder -> next;
	holder -> next = iter;
	iter -> next = NULL;
	write(1, "ra\n", 3);
}
