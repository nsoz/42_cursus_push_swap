/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:14:33 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 21:55:37 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_low(t_lst *b_list)
{
	t_lst	*iter;

	iter = b_list;
	while (iter->next != NULL)
	{
		if (iter->index < iter->next->index)
			iter = iter->next;
		else
			break ;
	}
	if (iter->next == NULL)
		return (0);
	else
		return (1);
}

int	ft_cost_filler(int index, t_lst *male_list, t_lst *female_list, int flag)
{
	if (flag == 1)
		return ((ft_calculate_in_list(index, male_list,
					ft_lst_size(male_list), flag) + 1) + ft_calculate_in_list
			((index - 1), female_list,
				ft_lst_size(female_list), flag));
	else
		return ((ft_calculate_in_list(index, male_list,
					ft_lst_size(male_list), flag) + 1) + ft_calculate_in_list
			((index + 1), female_list,
				ft_lst_size(female_list), flag));
}

int	ft_cost_calculate(t_lst *male_list, t_lst *female_list, int flag)
{
	int		cost_of_ret;
	t_lst	*iter;
	int		minest_costs_index;

	iter = male_list;
	cost_of_ret = ft_cost_filler(iter->index, male_list, female_list, flag);
	minest_costs_index = iter->index;
	iter = iter->next;
	while (iter != NULL)
	{
		if (cost_of_ret <= ft_cost_filler
			(iter->index, male_list, female_list, flag))
			iter = iter->next;
		else
		{
			cost_of_ret = ft_cost_filler
				(iter->index, male_list, female_list, flag);
			minest_costs_index = iter->index;
		}
	}
	return (minest_costs_index);
}

void	ft_b_to_a(t_lst *a_list, t_lst *b_list)
{
	int	len;
	int	minest_costs;
	int	minest;

	len = ft_lst_size(b_list);
	while (len)
	{
		minest_costs = ft_find_index(b_list,
				ft_cost_calculate(b_list, a_list, 2), 2);
		ft_processes(&b_list, &a_list, minest_costs, 2);
		do_pa(&a_list, &b_list);
		len--;
	}
	len = ft_lst_size(a_list);
	while (ft_is_sorted_low(a_list))
	{
		minest = ft_find_index(a_list, ft_find_lowest(a_list), 1);
		if ((len - minest) < minest)
			do_rra(&a_list);
		else
			do_ra(&a_list);
	}
	ft_lst_free(a_list, 1);
}

void	ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		minest_costs;
	int		len;

	b_list = NULL;
	do_pb(&a_list, &b_list);
	do_pb(&a_list, &b_list);
	len = ft_lst_size(a_list);
	while (len > 3)
	{
		minest_costs = ft_find_index(a_list,
				ft_cost_calculate(a_list, b_list, 1), 1);
		ft_processes(&a_list, &b_list, minest_costs, 1);
		do_pb(&a_list, &b_list);
		len--;
	}
	ft_sort_for_tw(&a_list, 1);
	ft_b_to_a(a_list, b_list);
}
