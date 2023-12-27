/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:37:32 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:05:21 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_dup(t_lst *list_a)
{
	t_lst	*tmp;
	t_lst	*holder;

	tmp = list_a;
	while (tmp != NULL)
	{
		holder = tmp->next;
		while (holder != NULL)
		{
			if (tmp->data == holder->data)
				return (1);
			holder = holder->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
