/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:49:58 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/15 11:52:47 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				valid_dup(int *a, int len)
{
	int			i;
	int			j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_final_check(int *arr, int len, int amount)
{
	int			i;

	i = -1;
	if (amount != len)
		return (0);
	while (++i < len - 1)
		if (arr[i] > arr[i + 1])
			return (0);
	return (1);
}

int				ft_check(int *arr, int len)
{
	int			i;

	i = -1;
	while (++i < len - 1)
		if (arr[i] > arr[i + 1])
			return (0);
	return (1);
}

void			show_num_of_opr(int num, t_stacks *ps)
{
	if (num)
	{
		ft_putstr("Number of operations = ");
		ft_putstr("\033[0;32m");
		ft_putnbr(ps->number_of_ops);
		ft_putchar('\n');
	}
}
