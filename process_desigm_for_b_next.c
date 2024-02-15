/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_desigm_for_b_next.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:08:55 by muoz              #+#    #+#             */
/*   Updated: 2024/02/13 22:03:14 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_proces_rev_b(int *directory, t_lst **male_list, t_lst **female_list)
{
	int	repeat;
	int	rest;

	repeat = 0;
	if (directory[REPEAT_A] > directory[REPEAT_B])
	{
		repeat = directory[REPEAT_B];
		rest = directory[REPEAT_A] - directory[REPEAT_B];
		while (repeat--)
			do_rrr(male_list, female_list);
		while (rest--)
			do_rra(female_list);
	}
	else
	{
		repeat = directory[REPEAT_A];
		rest = directory[REPEAT_B] - directory[REPEAT_A];
		while (repeat--)
			do_rrr(male_list, female_list);
		while (rest--)
			do_rrb(male_list);
	}
}

void	ft_proces_rev(int *directory, t_lst **male_list, t_lst **female_list)
{
	int	repeat;
	int	rest;

	repeat = 0;
	if (directory[REPEAT_A] > directory[REPEAT_B])
	{
		repeat = directory[REPEAT_B];
		rest = directory[REPEAT_A] - directory[REPEAT_B];
		while (repeat--)
			do_rrr(male_list, female_list);
		while (rest--)
			do_rra(male_list);
	}
	else
	{
		repeat = directory[REPEAT_A];
		rest = directory[REPEAT_B] - directory[REPEAT_A];
		while (repeat--)
			do_rrr(male_list, female_list);
		while (rest--)
			do_rrb(female_list);
	}
}
