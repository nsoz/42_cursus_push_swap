#include "push_swap.h"

int	ft_find_relevants_index(t_lst *a_list, int relevant)
{
	t_lst	*iter;
	int		i;

	i = 1;
	iter = a_list;
	while (iter != NULL)
	{
		if ((iter->index) == relevant)
			return (i);
		iter = iter->next;
		i++;
	}
	return (-1);
}

int ft_find_closest(t_lst *list, int aforementioned, int distance) ///kendinden küçük en yakın datayı gösterir ama kendinden küçük yoksa kendinden büyük en küçük datayı vermeli
{
    t_lst	*iter;

    iter = list;
    while (iter != NULL)
	{
		if (aforementioned > iter->index)
			if (iter->index > distance)
				distance = iter->index;
        iter = iter->next;
    }
	if ((iter == NULL) && (distance == 0)) //kendinden büyük en küçük indexi bul
	{
		iter = list;
		distance = 2147483647; 
		while (iter != NULL)
		{												//norm için distance = ft_high_closest() fonksiyonu yap
			if (aforementioned < iter->index)
				if (iter->index < distance)
					distance = iter->index;
			iter = iter->next;
		}
	}
	return (distance);
}


int	ft_find_index(t_lst *list, int aforementioned)
{
	int i;
	t_lst *iter;

	i = 1;
	iter = list;
	while (iter != NULL && iter->index != aforementioned)
	{
		iter = iter->next;
		i++;
	}
	if (iter == NULL)
		return(ft_find_index(list, ft_find_closest(list, (aforementioned), 0)));
	return (i);
}


int	ft_calculate_in_list(int index, t_lst *list, int len)
{
	int i;
	int distance;

	i = ft_find_index(list, index);
	distance = (len - i);
	if (distance < i)
		return (distance + 1);
	else
		return (i - 1);
}

int	ft_cost_filler(int index, t_lst *b_list, t_lst *a_list, int len)
{
	return ((ft_calculate_in_list(index, a_list, len) + 1) + ft_calculate_in_list((index - 1), b_list, len));
}

int	ft_cost_calculate(t_lst *a_list, t_lst *b_list, int len)
{
	int 	cost_of_ret;
	t_lst	*iter;
	int 	minest_costs_index;

	iter = a_list;
	cost_of_ret = ft_cost_filler(iter->index, b_list, a_list, len);
	printf(">>%d\n", cost_of_ret);
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
	int		len;

	b_list = NULL;
	do_pb(&a_list, &b_list);
	do_pb(&a_list, &b_list);
	len_a = ft_lst_size(a_list);
	while(len)
	{
		minest_costs_index_in_lst = ft_find_index(a_list, ft_cost_calculate(a_list, b_list, len));
		// printf("***=%d", minest_costs_index_in_lst); 
		ft_processes(a_list, b_list, cost_of_index, len_a);
		len--;
	}
	return(0);
}
