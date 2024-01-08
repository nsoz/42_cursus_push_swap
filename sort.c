/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:07:19 by muoz              #+#    #+#             */
/*   Updated: 2024/01/08 09:35:52 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_descending_order(t_lst **b_list)
{
	t_lst	**iter;

	// t_lst	*templist;
	iter = b_list;
	// templist = *b_list;
	// while (templist != NULL)
	// {
	// 	printf("->>%d\n", templist->data);
	// 	templist = templist->next;
	// }
	if ((*iter)->next != NULL && (*iter)->data < (*iter)->next->data)
		do_rb(b_list);
}

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
		while (minest != -1)
		{
			do_ra(&(*a_list));
			minest--;
		}
	// write(1, "afterr_pre :", 12);
	// liste_yazdir(*a_list, "A LİST");
}

int	ft_find_minest_index(t_lst *a_list)
{
	int		min;
	int		min_index;
	t_lst	*iter;

	min_index = 0;
	min = 0;
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
			return (-2);
		while (iter != NULL)
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

void	ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		len_of_list;
	int		minest_index;

	b_list = NULL;

	do_pb(&a_list, &b_list);
	do_pb(&a_list, &b_list);
	ft_sort_descending_order(&b_list);
	len_of_list = ft_lst_size(a_list);

	while (len_of_list)
	{
		minest_index = algorithm_simulation(a_list, b_list); // -2 dönme koşulu var if a == 1
		printf("~~~~\n %dinci giriş : minest index : %d\n~~~~", len_of_list, minest_index);

		ft_preparation_to_push(&a_list, minest_index, ft_lst_size(a_list));

		do_pb(&a_list, &b_list);
		len_of_list--;
		liste_yazdir(a_list, "A stack");
		liste_yazdir(b_list, "B stack");
	}
	a_list = malloc(ft_lst_size(b_list) * sizeof(t_lst));
	a_list->data = (int)NULL;
	a_list->next = NULL;
	len_of_list = ft_lst_size(b_list);
	while (len_of_list--)
		do_pa(&a_list, &b_list);
}
