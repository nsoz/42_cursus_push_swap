/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:49:10 by muoz              #+#    #+#             */
/*   Updated: 2024/02/15 19:55:54 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	wc_count(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' '
				|| str[i + 1] == '\t' || str[i + 1] == '\0'))
			wc++;
		i++;
	}
	return (wc);
}

char	*fill(char *str, int index, t_lst *list_a)
{
	int		len;
	int		ret_index;
	char	*ret;
	int		check_digits;

	len = index;
	ret_index = 0;
	check_digits = 1;
	while (str[len] && !(str[len] == ' ' || str[len] == '\t'))
		len++;
	ret = malloc((len - index + 1) * sizeof(char));
	while (index < len)
	{
		ret[ret_index] = str[index];
		if ((ret[ret_index] >= '0') && (ret[ret_index] <= '9'))
			check_digits = 0;
		index++;
		ret_index++;
	}
	if (check_digits)
		ft_lst_free(list_a, 2);
	ret[ret_index] = '\0';
	return (ret);
}

char	**ft_split(char *str, t_lst *list_a)
{
	int			i;
	char		**ret;
	int			len;
	int			f;

	i = 0;
	f = 0;
	len = wc_count(str);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && !(str[i] == ' ' || str[i] == '\t'))
			ret[f++] = fill(str, i, list_a);
		while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
			i++;
	}
	ret[f] = NULL;
	return (ret);
}

int	ft_is_dup(t_lst *list_a)
{
	t_lst	*tmp;
	t_lst	*holder;

	tmp = list_a;
	while (tmp != NULL)
	{
		holder = tmp->next;
		while (holder != NULL)
		{
			if (tmp->data == holder->data)
				return (1);
			holder = holder->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

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
			ft_lst_free(list_a, 2);
	}
	if (*str && (*str != ' ' && *str != '	'))
		ft_lst_free(list_a, 2);
	return (result * sign);
}
