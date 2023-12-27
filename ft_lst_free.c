/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:05:41 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:44:16 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
