/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_tw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:09:05 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 21:51:54 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_in_list(t_lst *list, int aff)
{
	t_lst	*iter;
	int		loc;

	loc = 1;
	iter = list;
	while (iter != NULL && iter->index != aff)
	{
		iter = iter->next;
		loc++;
	}
	return (loc);
}

void	ft_sort_for_tw(t_lst **a_list, int flag)
{
	int	min;
	int	max;

	min = ft_find_in_list(*a_list, ft_find_lowest(*a_list));
	max = ft_find_in_list(*a_list, ft_find_highest(*a_list));
	if ((max == 1) && (min == 3))
	{
		swap_a(*a_list);
		do_rra(&*a_list);
	}
	else if ((max == 1) && (min == 2))
		do_ra(&*a_list);
	else if ((max == 2) && (min == 3))
		do_rra(&*a_list);
	else if ((max == 3) && (min == 2))
		swap_a(*a_list);
	else if ((max == 2) && (min == 1))
	{
		do_rra(&*a_list);
		swap_a(*a_list);
	}
	if (flag == 2)
		ft_lst_free(*a_list, 1);
}
