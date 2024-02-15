/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new_utils_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:53:39 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 21:15:46 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_lst *list, int aforementioned, int flag)
{
	int		i;
	t_lst	*iter;

	i = 1;
	iter = list;
	while (iter != NULL && iter->index != aforementioned)
	{
		iter = iter->next;
		i++;
	}
	if (iter == NULL)
	{
		if (flag == 1)
			return (ft_find_index(list,
					ft_find_closest(list, (aforementioned), 0, flag), flag));
		else
			return (ft_find_index(list,
					ft_find_closest(list, (aforementioned), 1110, flag), flag));
	}
	return (i);
}

int	ft_calculate_in_list(int index, t_lst *list, int len, int flag)
{
	int	i;
	int	distance;

	i = ft_find_index(list, index, flag);
	distance = (len - i);
	if (distance == 0)
		return (1);
	if (distance < i)
		return (distance + 1);
	else
		return (i - 1);
}

int	ft_closer_to_start_or_end(int index, t_lst *list, int len)
{
	int	i;
	int	distance;

	i = ft_find_index(list, index, 1);
	distance = (len - i);
	if (distance < i)
		return (1);
	else
		return (0);
}
