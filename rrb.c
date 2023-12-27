/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:01:13 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:26:01 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_b(t_lst **b_list)
{
	t_lst	*iter;
	int		i;

	i = 0;
	iter = *b_list;
	while (iter->next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *b_list;
	(*b_list) = iter;
	while (i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
	write(1, "rrb\n", 4);
}
