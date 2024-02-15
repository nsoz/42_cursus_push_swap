/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:04:41 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 23:07:46 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pre_sort(t_lst *list_a)
{
	if (ft_is_dup(list_a))
		ft_lst_free(list_a, 2);
	ft_index_sort(list_a);
	if (!(ft_is_sorted_low(list_a)))
	{
		ft_lst_free(list_a, 1);
		return ;
	}
	if (ft_lst_size(list_a) >= 5)
		ft_sort(list_a);
	else
	{
		if (ft_lst_size(list_a) == 3)
			ft_sort_for_tw(&list_a, 2);
		else if (ft_lst_size(list_a) == 4)
			ft_sort_for_fr(list_a);
		else if (ft_lst_size(list_a) == 2)
			ft_sort_for_to(list_a);
	}
}

int	main(int ac, char **av)
{
	int		av_counter;
	char	**ret_of_split;
	int		split_layer;
	t_lst	*list_a;

	list_a = NULL;
	split_layer = 0;
	av_counter = 0;
	while (++av_counter < ac && ac != 0)
	{
		ret_of_split = ft_split(av[av_counter], list_a);
		while (ret_of_split[split_layer])
		{
			ft_lstadd(&list_a,
				ft_atol(ret_of_split[split_layer], list_a, 0, 0));
			free(ret_of_split[split_layer]);
			split_layer++;
		}
		free(ret_of_split);
		split_layer = 0;
	}
	ft_pre_sort(list_a);
	system("leaks push_swap");
	return (0);
}
