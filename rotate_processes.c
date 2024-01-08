/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:43:22 by muoz              #+#    #+#             */
/*   Updated: 2024/01/05 18:13:23 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_lst_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_lst **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	do_rb(t_lst **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	do_rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}