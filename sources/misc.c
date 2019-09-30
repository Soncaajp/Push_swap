/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:55:16 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/19 11:12:05 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void				add_value(int **t, int *src, int n)
{
	int				i;
	int				*point;

	if (n != 0)
	{
		i = 0;
		point = *t;
		while (i < n)
		{
			point[i] = src[i];
			i++;
		}
		free(src);
		*t = point;
	}
}

void				add_op(t_stacks *ps, t_ops **head, char *src)
{
	t_ops		*new;
	t_ops		*pointer;

	ft_operation(ps, src);
	pointer = *head;
	if (!pointer->op)
		pointer->op = ft_strdup(src);
	else
	{
		while (pointer->next)
			pointer = pointer->next;
		new = (t_ops*)malloc(sizeof(t_ops));
		new->op = ft_strdup(src);
		new->next = NULL;
		pointer->next = new;
	}
	*head = pointer;
}

void				ft_print(t_ops *head, t_stacks *ps)
{
	t_ops		*new;

	while (head)
	{
		new = head;
		ft_putendl(head->op);
		head = head->next;
		ft_strdel(&new->op);
		free(new);
		ps->number_of_ops++;
	}
}

void				ft_res_sort(int *src, int n)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = 0;
	while (i < n)
	{
		tmp = src[i];
		src[i] = src[n - 1];
		src[n - 1] = tmp;
		i++;
		n--;
	}
}

int					ft_med(int *arr, int len, int f)
{
	int				result;
	int				*tmp;

	tmp = ft_copy(arr, len);
	quicksort(tmp, 0, len - 1, 0);
	if (f != 97)
		ft_res_sort(tmp, len);
	result = (tmp[len / 2]);
	free(tmp);
	return (result);
}
