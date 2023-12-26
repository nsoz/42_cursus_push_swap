void	reverse_rotate_both_of_them(struct lst **a_list, struct lst **b_list)
{
	reverse_rotate_a(&*a_list);
	reverse_rotate_b(&*b_list);
	write(1, "rrr\n", 4);
}