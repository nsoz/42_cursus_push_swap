#include "push_swap.h"

int	ft_find_highest(t_lst *list)
{
	t_lst *iter;
	int		distance;
	
	distance = 0;
	iter = list;
	while (iter != NULL)
	{	
		if (distance < iter->index)
				distance = iter->index;
		iter = iter->next;
	}
	return (distance);
}

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

int ft_find_closest(t_lst *list, int aforementioned, int distance)
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
	if ((iter == NULL) && (distance == 0))
		return (ft_find_highest(list));
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

int	ft_closer_to_start_or_end(int index, t_lst *list, int len)
{
	int i;
	int distance;

	i = ft_find_index(list, index);
	distance = (len - i);
	if (distance < i)
		return (1);
	else
		return (0);
}

//ilk başta küçük en büyüğüğü bulmalısın
// yoksa büyük en büyüğü bulmalısın !!!!!!!