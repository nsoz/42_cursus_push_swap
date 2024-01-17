#include "push_swap.h"

void	print_list(t_lst *lst)
{
	t_lst	*iter;
	int		index;

	iter = lst;
	index = 0;
	while (iter != NULL)
	{
		// printf("index = %d, value = %d\n", index, iter->data);
		index++;
		iter = iter->next;
	}
}

int	ft_is_sorted_low(t_lst *b_list)
{
	t_lst *iter;

	iter = b_list;
	// printf("1111111111");
	// print_list(iter);
	while (iter->next != NULL)
	{
		if (iter->index > iter->next->index)
			iter = iter->next;
		else
			break;
	}
	if(iter->next == NULL)
		return (0);
	else
		return (1);
}

int	ft_cost_filler(int index, t_lst *b_list, t_lst *a_list, int len)
{
	return ((ft_calculate_in_list(index, a_list, len) + 1) + ft_calculate_in_list((index - 1), b_list, ft_lst_size(b_list)));
}

int	ft_cost_calculate(t_lst *a_list, t_lst *b_list, int len)
{
	int 	cost_of_ret;
	t_lst	*iter;
	int 	minest_costs_index;

	iter = a_list;
	cost_of_ret = ft_cost_filler(iter->index, b_list, a_list, len);
	minest_costs_index = iter->index;
	iter = iter->next;

	while (iter != NULL)
	{
		if (cost_of_ret <= ft_cost_filler(iter->index, b_list, a_list, len))
			iter = iter->next;
		else
		{
			cost_of_ret = ft_cost_filler(iter->index, b_list, a_list, len);
			minest_costs_index = iter->index;
		}
	}
	return (minest_costs_index);
}

t_lst	*ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		minest_costs_index_in_lst;
	int		len_a;

	b_list = NULL;
	do_pb(&a_list, &b_list);
	do_pb(&a_list, &b_list); //first_push fonksiyonu yazabilirsin
	len_a = ft_lst_size(a_list);
	while(len_a)
	{
		minest_costs_index_in_lst = ft_find_index(a_list, ft_cost_calculate(a_list, b_list, len_a));
		ft_processes(&a_list, &b_list, minest_costs_index_in_lst, len_a);
		do_pb(&a_list, &b_list);
		len_a--;
	}
	while (ft_is_sorted_low(b_list))
	{
		if (ft_closer_to_start_or_end(ft_find_highest(b_list), b_list, ft_lst_size(b_list)))
			do_rrb(&b_list);
		else
			do_rb(&b_list);
	}
	while(b_list != NULL)
			do_pa(&a_list, &b_list);
	// liste_yazdir(a_list, "a_list");
	return(0);
}
