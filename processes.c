#include "push_swap.h"

int	ft_rev_or_rotate(prophet_index, len_a)
{
	int distance;

	distance = len_a - prophet_index;
	if (distance < prophet_index)
		return(2); //rev
	else
		return(1); //rotate
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


int	ft_finder(t_lst *a_list, int prophet_index_holder)
{
	t_lst	*iter;
	int		ret;

	iter = a_list;
	while (prophet_index_holder--)
		iter = iter->next;
	ret = iter->index;
	return(ret);
}

void	ft_processes(t_lst *a_list, t_lst *b_list, int prophet_index, int len_a)
{
	int	aforementioned_index;
	int	flag_for_a;
	int	flag_for_b;
	int	repeat_a;
	int	repeat_b;

	aforementioned_index = ft_finder(a_list, (prophet_index - 1));
	repeat_a = ft_repeat_calculate(prophet_index, len_a);
	repeat_b = ft_repeat_calculate(prophet_index, ft_calculate_in_list((aforementioned_index - 1), b_list, ft_lst_size(b_list)));
	flag_for_a = ft_rev_or_rotate(aforementioned_index, len_a);
	flag_for_b = ft_rev_or_rotate(ft_find_index((aforementioned_index - 1), b_list), ft_lst_size(b_list));
	ft_processes_design(repeat_a, repeat_b, flag_for_a, flag_for_b);
}
