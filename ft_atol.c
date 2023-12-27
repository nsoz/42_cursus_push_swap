/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:37:23 by muoz              #+#    #+#             */
/*   Updated: 2023/12/27 02:51:05 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str, t_lst *list_a, int check, long result)
{
	int		sign;

	sign = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13) || (*str == '0'))
		str++;
	if (*str == '-')
		sign = -1;
	while (*str == '-' || *str == '+')
	{
		str++;
		check++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if ((result * sign) > 2147483647
			|| (result * sign) < -2147483648 || check > 1)
			ft_lst_free(list_a);
	}
	if (*str && (*str != ' ' && *str != '	'))
		ft_lst_free(list_a);
	return (result * sign);
}
