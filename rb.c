/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:00:44 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:19:23 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
