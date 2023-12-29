/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:51:13 by muoz              #+#    #+#             */
/*   Updated: 2023/12/29 22:07:54 by muoz             ###   ########.fr       */
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
	struct s_lst	*next;
}	t_lst;

void	swap_both_of_them(t_lst *node_a, t_lst *node_b);
void	swap_b(t_lst *node);
void	swap_a(t_lst *node);
void	reverse_rotate_both_of_them(t_lst **a_list, t_lst **b_list);
void	reverse_rotate_b(t_lst **b_list);
void	reverse_rotate_a(t_lst **a_list);
void	rotate_a(t_lst **list);
void	rotate_b(t_lst **list);
void	rotate_both_of_them(t_lst **a_list, t_lst **b_list);
void	push_to_b(t_lst **node_a, t_lst **node_b);
void	push_to_a(t_lst **node_a, t_lst **node_b);
void	ft_lstadd(t_lst **list, int a);
char	**ft_split(char *str, t_lst *list_a);
long	ft_atol(char *str, t_lst *list_a, int check, long result);
int		ft_is_dup(t_lst *list_a);
void	ft_lst_free(t_lst *list_a);
int		ft_lst_size(t_lst *lst_x);

#endif