#include "push_swap.h"

int	ft_rev_or_rotate(int prophet_index, int len)
{
	if (len == 1)
		return (0);
	int distance;

	distance = len - prophet_index;
	if (distance < prophet_index)
		return(2); //rev
	else
		return(1); //rotate
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

void	ft_processes(t_lst **a_list, t_lst **b_list, int prophet_index, int len_a)
{
	int	aforementioned_index;
	int	directory[4];

	// if (prophet_index == -1)
	// 	aforementioned_index = a_list->index;
	aforementioned_index = ft_finder(*a_list, (prophet_index - 1));
	// printf("affor: %d\n", aforementioned_index);
	// printf("/n/////////////n");
	directory[REPEAT_A] = ft_calculate_in_list(aforementioned_index, *a_list, len_a);   //repeat_a
	// printf("/n/////////////n");
	// printf(">RA>>>%d\n", directory[REPEAT_A]);
	// printf("\n********\n");
	directory[REPEAT_B] = ft_calculate_in_list((aforementioned_index + 1), *b_list, ft_lst_size(*b_list));  //repeat_b
	// printf("\n********\n");
	// printf(">RB>>>%d\n", directory[REPEAT_B]);
	directory[FLAG_FOR_A] = ft_rev_or_rotate(prophet_index, len_a);   //flag_for_a
	// printf(">FFA>>>%d\n", directory[FLAG_FOR_A]);
	directory[FLAG_FOR_B] = ft_rev_or_rotate(ft_find_index(*b_list, (aforementioned_index + 1)), ft_lst_size(*b_list)); //flag_for_b
	// printf(">FFB>>>%d\n", directory[FLAG_FOR_B]);
	ft_processes_design(directory, a_list, b_list);
}
