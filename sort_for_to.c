/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:08:40 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 19:55:25 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_for_to(t_lst *a_list)
{
	t_lst	*iter;

	iter = a_list;
	if (iter->index > iter->next->index)
		swap_a(a_list);
	ft_lst_free(a_list, 1);
}
