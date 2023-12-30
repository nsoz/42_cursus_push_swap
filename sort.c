/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:07:19 by muoz              #+#    #+#             */
/*   Updated: 2023/12/30 17:29:37 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_one_is_esaier(t_lst *a_list, t_lst b_list)
{
	int		len_a;
	int		len_b;
	int		*arr;
	int		index_of_arr;
	int		ret;
	t_lst	*iter;
	int		index_holder;

	iter = b_list;
	index_of_arr = 0;
	index_holder = index_of_arr;
	len_b = ft_lst_size(b_list);
	len_a = ft_lst_size(a_list);
	arr = (int *)malloc(len_b * sizeof(int));
	while (b_len > index_of_arr)
	{
		while ((iter->next != NULL) && (index_holder-- >= 0))
			iter = iter->next;
		ret = a_list->data - iter->data;
		iter = b_list;
		arr[index_of_arr] = a_list->data - ret;
		index_of_arr++;
		index_holder = index_of_arr;
	}
}

void	ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		len_of_a_list;
	int		esaier_one;

	len_of_a_list = ft_lst_size(a_list);
	b_list = (t_lst *)malloc(len_of_a_list * sizeof(b_list));
	push_to_b(&a_list, &b_list);
	push_to_b(&a_list, &b_list);
	while (len_of_a_list)
	{
		esaier_one = which_one_is_esaier(a_list, b_list);
		len_of_a_list--;
	}
}
