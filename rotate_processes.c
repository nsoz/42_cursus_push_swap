/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:43:22 by muoz              #+#    #+#             */
/*   Updated: 2023/12/29 21:43:23 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_lst **list)
{
	t_lst	*iter;
	t_lst	*holder;

	iter = *list;
	*list = (*list)->next;
	holder = *list;
	while (holder -> next != NULL)
		holder = holder -> next;
	holder -> next = iter;
	iter -> next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_lst **list)
{
	t_lst	*iter;
	t_lst	*holder;

	iter = *list;
	*list = (*list)->next;
	holder = *list;
	while (holder->next != NULL)
		holder = holder -> next;
	holder -> next = iter;
	iter -> next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_both_of_them(t_lst **a_list, t_lst **b_list)
{
	rotate_a(&*a_list);
	rotate_b(&*b_list);
	write(1, "rr\n", 3);
}
