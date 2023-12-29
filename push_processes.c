/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:41:15 by muoz              #+#    #+#             */
/*   Updated: 2023/12/29 21:41:16 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_from_list(t_lst **node)
{
	t_lst	*iter;

	iter = *node;
	*node = (*node)->next;
	free(iter);
}

void	push_to_b(t_lst **node_a, t_lst **node_b)
{
	t_lst	*new_node;

	new_node = (t_lst *)malloc(sizeof(t_lst));
	if (*node_a)
	{
		new_node->data = (*node_a)->data;
		remove_from_list(node_a);
		new_node->next = *node_b;
		*node_b = new_node;
	}
	write(1, "pb\n", 3);
}

void	push_to_a(t_lst **node_a, t_lst **node_b)
{
	t_lst	*new_node;

	if (*node_b)
	{
		new_node = (t_lst *)malloc(sizeof(t_lst));
		new_node->data = (*node_b)->data;
		remove_from_list(node_b);
		new_node->next = *node_a;
		*node_a = new_node;
	}
	write(1, "pa\n", 3);
}
