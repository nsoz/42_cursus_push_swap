/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_processes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:37:43 by muoz              #+#    #+#             */
/*   Updated: 2024/01/05 18:14:16 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*tail;
	t_lst	*before_tail;

	tail = get_lst_bottom(*stack);
	before_tail = get_lst_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_lst **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_lst **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_lst **stack_a, t_lst **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}