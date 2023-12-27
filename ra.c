/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:59:02 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:18:52 by muoz             ###   ########.fr       */
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
