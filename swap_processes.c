/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:36:42 by muoz              #+#    #+#             */
/*   Updated: 2023/12/29 21:36:43 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both_of_them(t_lst *node_a, t_lst *node_b)
{
	if ((node_a -> next != NULL) && (node_b -> next != NULL))
	{
		swap_a(node_a);
		swap_b(node_b);
	}
	write(1, "ss\n", 3);
}

void	swap_b(t_lst *node)
{
	int	tmp;

	if (node->next != NULL)
	{
		tmp = node -> data;
		node -> data = node->next->data;
		node -> next -> data = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_a(t_lst *node)
{
	int	tmp;

	if (node->next != NULL)
	{
		tmp = node -> data;
		node -> data = node->next->data;
		node -> next -> data = tmp;
	}
	write(1, "sa\n", 3);
}
