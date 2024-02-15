/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_design_for_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:34:44 by muoz              #+#    #+#             */
/*   Updated: 2024/02/13 23:29:22 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_proces_rot_b(int *directory, t_lst **male_list, t_lst **female_list)
{
	int	repeat;
	int	rest;

	repeat = 0;
	if (directory[REPEAT_A] > directory[REPEAT_B])
	{
		repeat = directory[REPEAT_B];
		rest = directory[REPEAT_A] - directory[REPEAT_B];
		while (repeat--)
			do_rr(male_list, female_list);
		while (rest--)
			do_ra(female_list);
	}
	else
	{
		repeat = directory[REPEAT_A];
		rest = directory[REPEAT_B] - directory[REPEAT_A];
		while (repeat--)
			do_rr(male_list, female_list);
		while (rest--)
		{
			do_rb(female_list);
		}
	}
}

void	ft_proces_flex_b(int *directory, t_lst **male_list, t_lst **female_list)
{
	int	repeat_for_a;
	int	repeat_for_b;

	if (directory[FLAG_FOR_A] == 1)
	{
		repeat_for_a = directory[REPEAT_A];
		while (repeat_for_a--)
			do_ra(female_list);
		repeat_for_b = directory[REPEAT_B];
		while (repeat_for_b--)
			do_rrb(male_list);
	}
	else
	{
		repeat_for_a = directory[REPEAT_A];
		while (repeat_for_a--)
			do_rra(female_list);
		repeat_for_b = directory[REPEAT_B];
		while (repeat_for_b--)
		{
			do_rb(male_list);
		}
	}
}

void	ft_processes_design_rotate_b(int *directory, t_lst **list, int listname)
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

void	ft_proces_revrot_b(int *directory, t_lst **list, int listname)
{
	int	repeat;

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

void	ft_proces_des_b(int *directory, t_lst **male_list, t_lst **female_list)
{
	if (directory[FLAG_FOR_A] == 2 && directory[FLAG_FOR_B] == 2)
		ft_proces_rev_b(directory, male_list, female_list);
	else if (directory[FLAG_FOR_A] == 1 && directory[FLAG_FOR_B] == 1)
		ft_proces_rot_b(directory, male_list, female_list);
	else if (directory[FLAG_FOR_A] != 0 && directory[FLAG_FOR_B] != 0)
		ft_proces_flex_b(directory, male_list, female_list);
	else if (directory[FLAG_FOR_A] == 1)
		ft_processes_design_rotate_b(directory, female_list, 'a');
	else if (directory[FLAG_FOR_A] == 2)
		ft_proces_revrot_b(directory, female_list, 'a');
	else if (directory[FLAG_FOR_B] == 1)
		ft_processes_design_rotate_b(directory, male_list, 'b');
	else
		ft_proces_revrot_b(directory, male_list, 'b');
}
