/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:08:19 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 21:53:08 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_top(t_lst **a_lst, int lowest)
{
	t_lst	*iter;

	iter = *a_lst;
	while (iter != NULL && iter->index != lowest)
	{
		do_ra(&*a_lst);
		iter = iter->next;
	}
}

void	ft_sort_for_fr(t_lst *a_list)
{
	int		smalest;
	t_lst	*b_list;

	b_list = NULL;
	smalest = ft_find_smalest(a_list);
	ft_get_top(&a_list, smalest);
	do_pb(&a_list, &b_list);
	ft_sort_for_tw(&a_list, 1);
	do_pa(&a_list, &b_list);
	ft_lst_free(a_list, 1);
}
