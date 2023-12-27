/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:03:53 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:15:05 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_lst **list, int a)
{
	t_lst	*node;
	t_lst	*temp;

	node = (t_lst *)malloc(sizeof(t_lst));
	node->data = a;
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
