/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:09:36 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 21:22:49 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_highest(t_lst *list)
{
	t_lst	*iter;
	int		distance;

	distance = 0;
	iter = list;
	while (iter != NULL)
	{
		if (distance < iter->index)
			distance = iter->index;
		iter = iter->next;
	}
	return (distance);
}

int	ft_find_lowest(t_lst *list)
{
	t_lst	*iter;
	int		distance;

	distance = 1110;
	iter = list;
	while (iter != NULL)
	{
		if (distance > iter->index)
			distance = iter->index;
		iter = iter->next;
	}
	return (distance);
}

int	ft_find_relevants_index(t_lst *a_list, int relevant)
{
	t_lst	*iter;
	int		i;

	i = 1;
	iter = a_list;
	while (iter != NULL)
	{
		if ((iter->index) == relevant)
			return (i);
		iter = iter->next;
		i++;
	}
	return (-1);
}

int	ft_find_close_else(t_lst *list, int aforementioned, int distance)
{
	t_lst	*iter;

	iter = list;
	while (iter != NULL)
	{
		if (aforementioned <= iter->index)
			if (iter->index < distance)
				distance = iter->index;
		iter = iter->next;
	}
	if ((iter == NULL) && (distance == 1110))
		return (ft_find_lowest(list));
	return (distance);
}

int	ft_find_closest(t_lst *list, int afor, int distance, int flag)
{
	t_lst	*iter;

	iter = list;
	if (flag == 1)
	{
		while (iter != NULL)
		{
			if (afor >= iter->index)
				if (iter->index > distance)
					distance = iter->index;
			iter = iter->next;
		}
		if ((iter == NULL) && (distance == 0))
			return (ft_find_highest(list));
		return (distance);
	}
	else
		return (ft_find_close_else(list, afor, distance));
}
