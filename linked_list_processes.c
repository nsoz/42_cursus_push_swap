/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_processes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:47:33 by muoz              #+#    #+#             */
/*   Updated: 2024/01/17 01:47:55 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_lst **list, int a)
{
	t_lst	*node;
	t_lst	*temp;

	node = (t_lst *)malloc(sizeof(t_lst));
	node->data = a;
	node->index = -1;
	node->next = NULL;
	if (*list == NULL)
		*list = node;
	else
	{
		temp = *list;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
}

void	ft_lst_free(t_lst *list_a)
{
	t_lst	*iter;

	while (list_a != NULL)
	{
		iter = list_a;
		list_a = list_a->next;
		free(iter);
	}
	write(1, "Error", 5);
	exit (1);
}

int	ft_lst_size(t_lst *lst_x)
{
	t_lst	*iter;
	int		i;

	i = 0;
	iter = lst_x;
	while (iter != NULL )
	{
		i++;
		iter = iter->next;
	}
	return (i);
}

t_lst	*get_lst_bottom(t_lst *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}
t_lst	*get_lst_before_bottom(t_lst *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}