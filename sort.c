/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:07:19 by muoz              #+#    #+#             */
/*   Updated: 2023/12/29 22:23:09 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		len_of_a_list;

	len_of_a_list = ft_lst_size(a_list);
	b_list = (t_lst *)malloc(len_of_a_list * sizeof(t_list));
	
}
