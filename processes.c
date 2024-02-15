/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:12:12 by muoz              #+#    #+#             */
/*   Updated: 2024/02/13 23:29:29 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rev_or_rotate(int prophet_index, int len)
{
	int	distance;

	if (len == 1)
		return (0);
	distance = len - prophet_index;
	if (distance < prophet_index)
		return (2);
	else
		return (1);
}

int	ft_finder(t_lst *a_list, int prophet_index_holder)
{
	t_lst	*iter;
	int		ret;

	iter = a_list;
	while (prophet_index_holder--)
		iter = iter->next;
	ret = iter->index;
	return (ret);
}

void	ft_processes_next(t_lst **male, t_lst **female, int prophet, int flag)
{
	int	afor;
	int	len;
	int	directory[4];

	len = ft_lst_size(*male);
	afor = ft_finder(*male, (prophet - 1));
	directory[REPEAT_B] = ft_calculate_in_list
		(afor, *male, len, 2);
	directory[REPEAT_A] = ft_calculate_in_list
		((afor + 1), *female,
			ft_lst_size(*female), 2);
	directory[FLAG_FOR_B] = ft_rev_or_rotate(prophet, len);
	directory[FLAG_FOR_A] = ft_rev_or_rotate(
			ft_find_index(*female, (afor + 1), 2),
			ft_lst_size(*female));
	ft_processes_design(directory, male, female, flag);
}

void	ft_processes(t_lst **male, t_lst **female, int prophet, int flag)
{
	int	afor;
	int	len;
	int	directory[4];

	len = ft_lst_size(*male);
	if (flag == 1)
	{
		afor = ft_finder(*male, (prophet - 1));
		directory[REPEAT_A] = ft_calculate_in_list(afor, *male, len, 1);
		directory[REPEAT_B] = ft_calculate_in_list((afor - 1), *female,
				ft_lst_size(*female), 1);
		directory[FLAG_FOR_A] = ft_rev_or_rotate(prophet, len);
		directory[FLAG_FOR_B] = ft_rev_or_rotate(
				ft_find_index(*female, (afor + 1), 1),
				ft_lst_size(*female));
		ft_processes_design(directory, male, female, flag);
	}
	else
		ft_processes_next(male, female, prophet, flag);
}
