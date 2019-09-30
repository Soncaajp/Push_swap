/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_implementation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:07:06 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/15 11:55:38 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_swap_two_first(int *int_arr, int len)
{
	int				swap;

	if (int_arr && len >= 2)
	{
		swap = int_arr[0];
		int_arr[0] = int_arr[1];
		int_arr[1] = swap;
	}
}

void				ft_rotate_up(int *int_arr, int len)
{
	int				i;
	int				tmp;

	if (len <= 1)
		return ;
	i = -1;
	tmp = int_arr[0];
	while (++i < len)
		int_arr[i] = (i + 1 == len) ? tmp : int_arr[i + 1];
}

void				ft_rotate_down(int *int_arr, int len)
{
	int				i;
	int				j;
	int				tmp;

	if (len <= 1)
		return ;
	i = 0;
	j = len - 1;
	tmp = int_arr[j];
	while (i <= j)
	{
		int_arr[j] = (j == 0) ? tmp : int_arr[j - 1];
		j--;
	}
}

void				ft_push_value_into_a(t_stacks *checker)
{
	int				*res;

	if (checker->len_b == 0)
		return ;
	res = (int*)malloc(sizeof(int) * (checker->len_a + 1));
	add_value(&res, checker->a, checker->len_a);
	checker->a = res;
	ft_rotate_down(checker->a, (checker->len_a + 1));
	checker->a[0] = checker->b[0];
	ft_rotate_up(checker->b, checker->len_b);
	checker->len_b--;
	checker->len_a++;
	if (checker->len_b != 0)
	{
		res = (int*)malloc(sizeof(int) * checker->len_b);
		add_value(&res, checker->b, checker->len_b);
		checker->b = res;
	}
	else
		free(checker->b);
}

void				ft_push_value_into_b(t_stacks *checker)
{
	int	*res;

	if (checker->len_a == 0)
		return ;
	res = (int*)malloc(sizeof(int) * (checker->len_b + 1));
	add_value(&res, checker->b, checker->len_b);
	checker->b = res;
	ft_rotate_down(checker->b, checker->len_b + 1);
	checker->b[0] = checker->a[0];
	ft_rotate_up(checker->a, checker->len_a);
	checker->len_a--;
	checker->len_b++;
	if (checker->len_a != 0)
	{
		res = (int*)malloc(sizeof(int) * checker->len_a);
		add_value(&res, checker->a, checker->len_a);
		checker->a = res;
	}
	else
		free(checker->a);
}
