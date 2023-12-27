/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:01:34 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:21:40 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
