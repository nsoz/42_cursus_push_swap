/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:51:13 by muoz              #+#    #+#             */
/*   Updated: 2024/01/08 03:56:27 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
void	ft_lst_free(t_lst *list_a);
int		ft_lst_size(t_lst *lst_x);
void	ft_sort(t_lst *a_list);
t_lst	*get_lst_bottom(t_lst *stack);
void	do_rra(t_lst **stack_a);
void	do_rrb(t_lst **stack_b);
void	do_rrr(t_lst **stack_a, t_lst **stack_b);
t_lst	*get_lst_before_bottom(t_lst *stack);
void	ft_index_sort(t_lst	*a_list);

#endif