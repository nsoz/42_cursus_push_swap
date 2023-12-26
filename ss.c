void swap_both_of_them(struct lst *node_a, struct lst *node_b)
{
	if ((node_a -> next != NULL) && (node_b -> next != NULL))
	{
		swap_a(node_a);
		swap_b(node_b);
	}
	write(1, "ss\n", 3);
}