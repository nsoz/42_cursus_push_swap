/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:01:01 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:25:50 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_lst **a_list)
{
	t_lst	*iter;
	int		i;

	i = 0;
	iter = *a_list;
	while (iter->next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *a_list;
	(*a_list) = iter;
	while (i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
	write(1 "rra\n", 4);
}
