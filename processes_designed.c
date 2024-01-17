#include "push_swap.h"

void	ft_processes_design_for_rev(int *directory, t_lst **a_list, t_lst **b_list)
{
	int repeat;
	int rest;

	repeat = 0;
	if (directory[REPEAT_A] > directory[REPEAT_B])
	{
		repeat = directory[REPEAT_B];
		rest = directory[REPEAT_A] - directory[REPEAT_B];
		while (repeat--)
			do_rrr(a_list, b_list);
		while (rest--)
			do_rra(a_list);
	}
	else
	{
		repeat = directory[REPEAT_A];
		rest = directory[REPEAT_B] - directory[REPEAT_A];
		while(repeat--)
			do_rrr(a_list, b_list);
		while (rest--)
			do_rrb(b_list);
	}
}

void	ft_processes_design_for_rotate(int *directory, t_lst **a_list, t_lst **b_list)
{
	int repeat;
	int rest;

	repeat = 0;
	if (directory[REPEAT_A] > directory[REPEAT_B])
	{
		repeat = directory[REPEAT_B];
		rest = directory[REPEAT_A] - directory[REPEAT_B];
		while (repeat--)
			do_rr(a_list, b_list);
		while (rest--)
			do_ra(a_list);
	}
	else
	{
		repeat = directory[REPEAT_A];
		rest = directory[REPEAT_B] - directory[REPEAT_A];
		while(repeat--)
			do_rr(a_list, b_list);
		while (rest--)
			do_rb(b_list);
	}
}

void	ft_processes_design_for_flexible(int *directory, t_lst **a_list, t_lst **b_list)
{
	int repeat_for_a;
	int repeat_for_b;

	if (directory[FLAG_FOR_A] == 1)
	{
		repeat_for_a = directory[REPEAT_A];
		while (repeat_for_a--)
			do_ra(a_list);
		repeat_for_b = directory[REPEAT_B];
		while (repeat_for_b--)
			do_rrb(b_list);
	}
	else
	{
		repeat_for_a = directory[REPEAT_A];
		while (repeat_for_a--)
			do_rra(a_list);
		repeat_for_b = directory[REPEAT_B];
		while (repeat_for_b--)
			do_rb(b_list);
	}
}

void	ft_processes_design_rotate(int *directory, t_lst **list, int listname)
{
	int	repeat;

	if (listname == 'a')
	{
		repeat = directory[REPEAT_A];
		while (repeat--)
			do_ra(list);
	}
	else
	{
		repeat = directory[REPEAT_B];
		while (repeat--)
			do_rb(list);
	}
}

void	ft_processes_design_revrotate(int *directory, t_lst **list, int listname)
{
	int repeat;

	if (listname == 'a')
	{
		repeat = directory[REPEAT_A];
		while (repeat--)
			do_rra(list);
	}
	else
	{
		repeat = directory[REPEAT_B];
		while (repeat--)
			do_rrb(list);
	}
}

void	ft_processes_design(int *directory, t_lst **a_list, t_lst **b_list)
{
	
	if (directory[FLAG_FOR_A] == 2 && directory[FLAG_FOR_B] == 2)
		ft_processes_design_for_rev(directory, a_list, b_list);
	else if (directory[FLAG_FOR_A] == 1 && directory[FLAG_FOR_B] == 1)
		ft_processes_design_for_rotate(directory, a_list, b_list);
	else if (directory[FLAG_FOR_A] != 0 && directory[FLAG_FOR_B] != 0)
		ft_processes_design_for_flexible(directory, a_list, b_list);
	else if (directory[FLAG_FOR_A] == 1)
		ft_processes_design_rotate(directory, a_list, 'a');
	else if (directory[FLAG_FOR_A] == 2)
		ft_processes_design_revrotate(directory, a_list, 'a');
	else if (directory[FLAG_FOR_B] == 1)
		ft_processes_design_rotate(directory, b_list, 'b');
	else
		ft_processes_design_revrotate(directory, b_list, 'b');
}