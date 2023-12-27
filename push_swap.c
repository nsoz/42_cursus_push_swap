/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:04:41 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 10:34:01 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		av_counter;
	char	**ret_of_split;
	int		split_layer;
	t_lst	*list_a;

	list_a = NULL;
	split_layer = 0;
	av_counter = 0;
	while (++av_counter < ac)
	{
		ret_of_split = ft_split(av[av_counter], list_a);
		while (ret_of_split[split_layer])
		{
			ft_lstadd(&list_a,
				ft_atol(ret_of_split[split_layer], list_a, 0, 0));
			free(ret_of_split[split_layer]);
			split_layer++;
		}
		split_layer = 0;
	}
	if (ft_is_dup(list_a))
		ft_lst_free(list_a);
	// ft_sort_algoritma(); //burada lstyi çek ve koy
	while (list_a != NULL)
	{
		printf("%d\n", list_a->data);
		list_a = list_a->next;
	}
	return (0);
}
