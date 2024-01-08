/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:04:41 by muoz              #+#    #+#             */
/*   Updated: 2024/01/08 18:11:11 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void liste_yazdir(t_lst *de, char *str)
{
	t_lst *iter1 = de;
	int size = 0;
	while (iter1 != NULL)
	{
		size++;
		iter1 = iter1->next;
	}
	t_lst *iter2 = de;
	printf("\n%s\n", str);
	while (iter2 != NULL)
	{
		printf("data: %d\ndataindex: %d\n\n", iter2->data, iter2->index);
		iter2 = iter2->next;
	}
	printf("list size: %d\n", size);
}

int	main(int ac, char **av)
{
	int		av_counter;
	char	**ret_of_split;
	int		split_layer;
	t_lst	*list_a;

	list_a = NULL;
	split_layer = 0;
	av_counter = 0; // ac = 4
	while (++av_counter < ac)
	{
		ret_of_split = ft_split(av[av_counter], list_a);
		while (ret_of_split[split_layer])
		{
			ft_lstadd(&list_a, ft_atol(ret_of_split[split_layer], list_a, 0, 0));
			free(ret_of_split[split_layer]);
			split_layer++;
		}
		split_layer = 0;
	}

	if (ft_is_dup(list_a))
		ft_lst_free(list_a);
	ft_index_sort(list_a);
	t_lst *new;
	new = ft_sort(list_a);
	// printf("\n----------------------------------\n");
	// liste_yazdir(new, "new_stack");
	// while (list_a != NULL)
	// {
	// 	printf("index_sort: %d\n", list_a->index);
	// 	list_a = list_a->next;
	// }
	// while (list_a != NULL)
	// {
	// 	printf("after_sort: %d\n", list_a->data);
	// 	list_a = list_a->next;
	// }
	return (0);
}
