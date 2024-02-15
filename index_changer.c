/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_changer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:58:33 by muoz              #+#    #+#             */
/*   Updated: 2024/02/11 23:21:30 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smalest(t_lst	*a_list)
{
	t_lst	*iter;
	int		minest;

	minest = a_list->data;
	iter = a_list;
	while (iter != NULL)
	{
		if (minest > iter->data)
			minest = iter->data;
		iter = iter->next;
	}
	return (minest);
}

int	ft_find_smalest_without_minest(t_lst	*a_list, int minest_holder)
{
	t_lst	*iter;
	int		minest;

	minest = 2147483647;
	iter = a_list;
	if (iter != NULL && iter->data == minest_holder)
		iter = iter->next;
	while (iter != NULL)
	{
		if (iter->data < minest_holder)
			iter = iter->next;
		else
		{
			if ((minest > iter->data) && (minest_holder != iter->data))
			{
				minest = iter->data;
				iter = iter->next;
			}
			else
				iter = iter->next;
		}
	}
	return (minest);
}

int	ft_find_relevant_index(t_lst *a_list, int relevant)
{
	t_lst	*iter;
	int		index;

	index = 1;
	iter = a_list;
	while (iter != NULL)
	{
		if ((iter->data) == relevant)
			return (index);
		iter = iter->next;
		index++;
	}
	return (-1);
}

void	ft_index_changer(t_lst *a_list,	int minest_index, int sorted_index)
{
	t_lst	*iter;

	iter = a_list;
	while (minest_index)
	{
		iter = iter->next;
		minest_index--;
	}
	iter->index = sorted_index;
}

void	ft_index_sort(t_lst	*a_list)
{
	t_lst	*iter;
	int		sorted_index;
	int		minest;
	int		index;

	sorted_index = 1;
	iter = a_list;
	minest = ft_find_smalest(a_list);
	index = ft_find_relevant_index(a_list, minest);
	ft_index_changer(a_list, (index - 1), sorted_index);
	sorted_index++;
	while (iter->next != NULL)
	{
		minest = ft_find_smalest_without_minest(a_list, minest);
		index = ft_find_relevant_index(a_list, minest);
		ft_index_changer(a_list, (index - 1), sorted_index);
		sorted_index++;
		iter = iter->next;
	}
}
