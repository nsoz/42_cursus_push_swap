#include "push_swap.h"

int	ft_find_minest(int *prophet_array, int len)
{
	int i;
	int ret;
	int lowest;
	
	lowest = prophet_array[0];
	i = 0;
	ret = 0;
	while (i < len)
	{
		if (lowest >= prophet_array[i])
		{
			ret = i;
			lovest = prophet_array[i];
		}
		i++;
	}
	return (ret);
}

void	ft_decision_a(int minest_index, t_lst *a_list, int len)
{
	int distance;
	int rr_flag;
	int r_flag;
	int cheapst;

	r_flag = 0;
	rr_flag = 0;
	distance = len - minest_index + 1;
	if (distance < minest_index)
	{
		rr_flag = 1;
		cheapst = distance;
	}
	else
	{
		r_flag = 1;
		cheapst = minest_index
	}
	ft_proces_begin(t_lst *a_list, t_lst *b_list, cheapst, r_flag, rr_flag);
}

ft_proceses(t_lst *a_list, t_lst *b_list, int *prophet_array, int len)
{
	int i;
	int minest;

	i = 0;
	minest_index = ft_find_minest(prophet_array, (len - 1));
	ft_decision(minest_index, a_list, (len - 1));
	ft_decision(minest_index, b_list, ft_lst_size(b_list));
}
