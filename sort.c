#include "push_swap.h"

int ft_find_closest(t_lst *list, int aforementioned)
{
    t_lst *iter;
	int	distance;
// 1 2 3 4 5 9 6 8 7 
    iter = list;
	distance = 0;
    while (iter != NULL)
	{
		if (aforementioned > iter->index)
			if (iter->index > distance)
				distance = iter->index;
        iter = iter->next;
    }
	printf("aff: %d, dist: %d\n", aforementioned, distance);
	return (distance);
}


int	ft_find_index(t_lst *list, int aforementioned) // blist 2
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
		return(ft_find_index(list, ft_find_closest(list, (aforementioned))));
	return (i);
}


int	ft_calculate_in_list(int index, t_lst *list, int len)// 2 blist 3
{
	int i;
	int distance;

	i = ft_find_index(list, index);// blsit 2 i = 2
	distance = (len - i) + 1;//dis = 1
	if (distance < i)
		return (distance);// 1döndü
	// else if(distance == 0)
	// 	return (1);
	else
		return (i - 1);
}

int	ft_cost_filler(int index, t_lst *b_list, t_lst *a_list, int len)//3 blist alist 3
{
	                        //      3     alist   3                                   2         b       3
	return ((ft_calculate_in_list(index, a_list, len) + 1) + ft_calculate_in_list((index - 1), b_list, len));
}

int	*ft_cost_calculate(t_lst *a_list, t_lst *b_list, int len)
{
	int *cost_of_ret;
	t_lst	*iter;
	int i;

	i = 0;
	iter = a_list;
	cost_of_ret = (int *)malloc(len * sizeof(int));
	while (len > i)
	{
		cost_of_ret[i] = ft_cost_filler(iter->index, b_list, a_list, len);//3 ,b, a, 3  
		iter = iter->next;
		i++;
	}
	return (cost_of_ret);
}

void	int_arr_yazdır(int *arr, int len)
{
	int i=-1;
	while (++i < len)
		printf(">>>>%d", arr[i]);
	printf("\n");
}

t_lst	*ft_sort(t_lst *a_list)
{
	t_lst	*b_list;
	int		*cost_of_index;
	int		len;

	b_list = NULL;
	do_pb(&a_list, &b_list);
	do_pb(&a_list, &b_list);
	len = ft_lst_size(a_list);
	// liste_yazdir(b_list, "B LİSTESİNE İLK İKİ DÜĞÜM EKLENDİ"); // kontrol edildi 
	while(len)
	{
		cost_of_index = ft_cost_calculate(a_list, b_list, len);
		int_arr_yazdır(cost_of_index, len);
		// ft_processes(a_list, b_list, cost_of_index, len);
		free(cost_of_index);
		len--;
	}
	//kapanmadan hemen önce free(const_of_index);
	//while kapanacak
	return(0);
}
