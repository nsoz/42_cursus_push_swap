/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:41:15 by muoz              #+#    #+#             */
/*   Updated: 2024/01/11 19:21:45 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	push(t_lst **src, t_lst **dest)
{
	t_lst	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	// liste_yazdir(*stack_a, "a liste işlem yapıldı");
	// write(1, "\n\n\n", 3);
}

void	do_pb(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	// liste_yazdir(*stack_b, "b liste işlem yapıldı");
	// write(1, "\n\n\n", 3);
}