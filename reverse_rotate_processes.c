/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_processes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:37:43 by muoz              #+#    #+#             */
/*   Updated: 2023/12/29 21:54:59 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	reverse_rotate_both_of_them(t_lst **a_list, t_lst **b_list)
{
	reverse_rotate_a(&*a_list);
	reverse_rotate_b(&*b_list);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_b(t_lst **b_list)
{
	t_lst	*iter;
	int		i;

	i = 0;
	iter = *b_list;
	while (iter->next != NULL)
	{
		iter = iter -> next;
		i++;
	}
	iter -> next = *b_list;
	(*b_list) = iter;
	while (i > 0)
	{
		iter = iter -> next;
		i--;
	}
	iter -> next = NULL;
	write(1, "rrb\n", 4);
}

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
	write(1, "rra\n", 4);
}
