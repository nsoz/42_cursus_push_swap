void	rotate_both_of_them(struct lst **a_list, struct lst **b_list)
{
	rotate_a(&*a_list);
	rotate_b(&*b_list);
	write(1, "rr\n", 3);
}
