/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_designed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 02:40:50 by muoz              #+#    #+#             */
/*   Updated: 2024/02/13 23:29:48 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_proces_rotate(int *directory, t_lst **male_list, t_lst **female_list)
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
			do_ra(male_list);
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

void	ft_proces_flex(int *directory, t_lst **male_list, t_lst **female_list)
{
	int	repeat_for_a;
	int	repeat_for_b;

	if (directory[FLAG_FOR_A] == 1)
	{
		repeat_for_a = directory[REPEAT_A];
		while (repeat_for_a--)
			do_ra(male_list);
		repeat_for_b = directory[REPEAT_B];
		while (repeat_for_b--)
			do_rrb(female_list);
	}
	else
	{
		repeat_for_a = directory[REPEAT_A];
		while (repeat_for_a--)
			do_rra(male_list);
		repeat_for_b = directory[REPEAT_B];
		while (repeat_for_b--)
			do_rb(female_list);
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

void	ft_processes_design_revrot(int *directory, t_lst **list, int listname)
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

void	ft_processes_design(int *dir, t_lst **male, t_lst **fmale, int flag)
{
	if (flag == 1)
	{
		if (dir[FLAG_FOR_A] == 2 && dir[FLAG_FOR_B] == 2)
			ft_proces_rev(dir, male, fmale);
		else if (dir[FLAG_FOR_A] == 1 && dir[FLAG_FOR_B] == 1)
			ft_proces_rotate(dir, male, fmale);
		else if (dir[FLAG_FOR_A] != 0 && dir[FLAG_FOR_B] != 0)
			ft_proces_flex(dir, male, fmale);
		else if (dir[FLAG_FOR_A] == 1)
			ft_processes_design_rotate(dir, male, 'a');
		else if (dir[FLAG_FOR_A] == 2)
			ft_processes_design_revrot(dir, male, 'a');
		else if (dir[FLAG_FOR_B] == 1)
			ft_processes_design_rotate(dir, fmale, 'b');
		else
			ft_processes_design_revrot(dir, fmale, 'b');
	}
	else
		ft_proces_des_b(dir, male, fmale);
}
