/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:51:13 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 20:29:02 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define REPEAT_A 0
# define REPEAT_B 1
# define FLAG_FOR_A 2
# define FLAG_FOR_B 3

typedef struct s_lst
{
	int				data;
	int				index;
	struct s_lst	*next;
}	t_lst;

void	liste_yazdir(t_lst *de, char *str);
void	swap_both_of_them(t_lst *node_a, t_lst *node_b);
void	swap_b(t_lst *node);
void	swap_a(t_lst *node);
void	reverse_rotate_both_of_them(t_lst **a_list, t_lst **b_list);
void	reverse_rotate_b(t_lst **b_list);
void	reverse_rotate_a(t_lst **a_list);
void	do_ra(t_lst **stack_a);
void	do_rb(t_lst **stack_b);
void	do_rr(t_lst **stack_a, t_lst **stack_b);
void	do_pb(t_lst **stack_a, t_lst **stack_b);
void	do_pa(t_lst **stack_a, t_lst **stack_b);
void	ft_lstadd(t_lst **list, int a);
char	**ft_split(char *str, t_lst *list_a);
long	ft_atol(char *str, t_lst *list_a, int check, long result);
int		ft_is_dup(t_lst *list_a);
void	ft_lst_free(t_lst *list_a, int flag);
int		ft_lst_size(t_lst *lst_x);
void	ft_sort(t_lst *a_list);
t_lst	*get_lst_bottom(t_lst *stack);
void	do_rra(t_lst **stack_a);
void	do_rrb(t_lst **stack_b);
void	do_rrr(t_lst **stack_a, t_lst **stack_b);
t_lst	*get_lst_before_bottom(t_lst *stack);
void	ft_index_sort(t_lst	*a_list);
int		ft_find_relevants_index(t_lst *a_list, int relevant);
int		ft_find_closest(t_lst *list, int afor, int distance, int flag);
int		ft_find_index(t_lst *list, int aforementioned, int flag);
int		ft_calculate_in_list(int index, t_lst *list, int len, int flag);
void	ft_processes_design(int *dir, t_lst **male, t_lst **fmale, int flag);
void	ft_proces_des_b(int *directory, t_lst **male_list, t_lst **female_list);
void	ft_processes(t_lst **male, t_lst **female, int prophet, int flag);
int		ft_closer_to_start_or_end(int index, t_lst *list, int len);
int		ft_find_highest(t_lst *list);
int		ft_find_smalest(t_lst	*a_list);
int		ft_find_lowest(t_lst *list);
void	ft_sort_for_tw(t_lst **a_list, int flag);
void	ft_sort_for_fr(t_lst *a_list);
void	ft_sort_for_to(t_lst *a_list);
void	ft_proces_rev_b(int *directory, t_lst **male_list, t_lst **female_list);
void	ft_proces_rev(int *directory, t_lst **male_list, t_lst **female_list);
int		ft_is_sorted_low(t_lst *b_list);

#endif