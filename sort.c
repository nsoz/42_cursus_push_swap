/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:07:19 by muoz              #+#    #+#             */
/*   Updated: 2024/01/08 19:21:27 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// en büyüğü en baştamı kontrolü yapan bir fonksiyon yap
int	ft_is_first_max(t_lst *b_list)
{
	if (b_list == NULL) 
        return 0;
	t_lst	*iter;
	int		high;

	high = b_list->index;
	iter = b_list;
	while (iter)
	{
		if(iter->index > high)
			break;
		iter = iter->next;
	}
	if (iter == NULL)
		return (0);
	else
		return (1);
}

void	ft_sort_descending_order(t_lst **b_list)
{
	if (b_list == NULL || *b_list == NULL)
    	return;
	t_lst	**iter;

	iter = b_list;
	//b lsitin en büyük datası ilkinde değilse while giren bir if bloğu yap
	if (ft_is_first_max(*b_list))
		while (iter != NULL && (*iter)->next != NULL && (*iter)->index < (*iter)->next->index)
		{
			do_rb(b_list);
			iter = &(*b_list);
		}
	else
		return;
	liste_yazdir((* b_list), "B LİSTESİ DİZAYN EDİLDİ:");
}

// bu kodda index sorunun var geçmesi gereken indexe geçebilmek için fazladan reverse işlemi yapıyor
void	ft_preparation_to_push(t_lst **a_list, int minest, int len)
{
	// write(1, "before_pre :", 12);
	// liste_yazdir(*a_list, "A LİST");
	int	distance;
	if (minest == -2)
		return ;
	distance = len - minest;
	if (distance < minest)
		while (distance != -1)
		{
			do_rra(&(*a_list));
			distance--;
		}
	else
	{
		int asd = 0;
		while (minest != 0)
		{
			asd++;
			do_ra(&(*a_list));
			minest--;
		}
	}	
}

int	ft_find_minest_index(t_lst *a_list)
{
	int		min;
	int		min_index;
	t_lst	*iter;

	min_index = 0;
	min = 2147483647;
	iter = a_list;
	while (iter != NULL)
	{
		if (iter->data < min)
			min = iter->data;
		iter = iter->next;
	}
	iter = a_list;
	while (iter != NULL)
	{
		if (iter->data == min)
			return (min_index);
		min_index++;
		iter = iter->next;
	}
	return (-1);
}

int	algorithm_simulation(t_lst *a_list, t_lst *b_list)
{
	int		index;
	int		minest;
	int		minindex;
	t_lst	*iter;
	int		min;

	min = 2147483647;
	iter = a_list;
	minest = b_list->data;
	index = 0;
	minindex = -1;
	if (a_list)
	{
		if (ft_lst_size(a_list) == 1)
			return (1);
		while (iter->next != NULL)
		{
			if (b_list->index < iter->index)
			{
				minest = iter->index - b_list->index;
				if (min > minest)
				{
					min = minest;
					minindex = index;
				}
			}
			iter = iter->next;
			index++;
		}
	}
	if (minindex == -1)
		return (ft_find_minest_index(a_list));
	return (minindex);
}

t_lst*	ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		len_of_list;
	int		minest_index;

	b_list = NULL;

	do_pb(&a_list, &b_list);
	do_pb(&a_list, &b_list); 
	// ft_sort_descending_order(&b_list);
	// len_of_list = ft_lst_size(a_list);
	
	while (1)
	{
		ft_sort_descending_order(&b_list);
		minest_index = algorithm_simulation(a_list, b_list);
		if (minest_index == -1)	
			break ;
		ft_preparation_to_push(&a_list, minest_index, ft_lst_size(a_list));
		do_pb(&a_list, &b_list);
	}
	len_of_list = ft_lst_size(b_list);
	while (len_of_list--)
		do_pa(&a_list, &b_list);





	printf("------------------------\n");
	liste_yazdir(b_list, "B LİSTENİN SORTTAKİ SON HALİ");
	liste_yazdir(a_list, "A LİSTENİN SORTTAKİ SON HALİ");
	printf("------------------------\n");
	return (a_list);
}
