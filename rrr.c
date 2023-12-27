/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:01:23 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:26:11 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both_of_them(t_lst **a_list, t_lst **b_list)
{
	reverse_rotate_a(&*a_list);
	reverse_rotate_b(&*b_list);
	write(1, "rrr\n", 4);
}
