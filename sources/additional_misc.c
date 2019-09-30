/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:25:44 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 15:29:30 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				*ft_copy(int *arr, int len)
{
	int		*tmp;
	int		i;

	tmp = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		tmp[i] = arr[i];
	return (tmp);
}

void			quicksort(int *list, int low, int high, int i)
{
	int			pivot;
	int			j;
	int			temp;

	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while (list[i] <= list[pivot] && i <= high)
				i++;
			while (list[j] > list[pivot] && j >= low)
				j--;
			(i < j) ? (temp = list[i]) : 0;
			(i < j) ? (list[i] = list[j]) : 0;
			(i < j) ? (list[j] = temp) : 0;
		}
		temp = list[j];
		list[j] = list[pivot];
		list[pivot] = temp;
		quicksort(list, low, j - 1, 0);
		quicksort(list, j + 1, high, 0);
	}
}

int				sort_by_med(int *arr, int len, int med, int stack)
{
	int			i;

	i = -1;
	while (++i < len)
	{
		if (stack == 97 && arr[i] < med)
			return (1);
		if (stack == 98 && arr[i] > med)
			return (1);
	}
	return (0);
}

static int		ft_transform_operations(t_ops *h, int cs)
{
	if (h->next == NULL)
		return (0);
	(!ft_strcmp(h->op, "sa") && !ft_strcmp(h->next->op, "sb")) ? cs = 1 : 0;
	(!ft_strcmp(h->op, "sb") && !ft_strcmp(h->next->op, "sa")) ? cs = 1 : 0;
	(!ft_strcmp(h->op, "ra") && !ft_strcmp(h->next->op, "rb")) ? cs = 2 : 0;
	(!ft_strcmp(h->op, "rb") && !ft_strcmp(h->next->op, "ra")) ? cs = 2 : 0;
	(!ft_strcmp(h->op, "rra") && !ft_strcmp(h->next->op, "rrb")) ? cs = 3 : 0;
	(!ft_strcmp(h->op, "rrb") && !ft_strcmp(h->next->op, "rra")) ? cs = 3 : 0;
	(!ft_strcmp(h->op, "pa") && !ft_strcmp(h->next->op, "pb")) ? cs = 4 : 0;
	(!ft_strcmp(h->op, "pb") && !ft_strcmp(h->next->op, "pa")) ? cs = 4 : 0;
	(!ft_strcmp(h->op, "ra") && !ft_strcmp(h->next->op, "rra")) ? cs = 5 : 0;
	(!ft_strcmp(h->op, "rra") && !ft_strcmp(h->next->op, "ra")) ? cs = 5 : 0;
	(!ft_strcmp(h->op, "rb") && !ft_strcmp(h->next->op, "rrb")) ? cs = 6 : 0;
	(!ft_strcmp(h->op, "rrb") && !ft_strcmp(h->next->op, "rb")) ? cs = 6 : 0;
	(cs == 1 || cs == 2 || cs == 3) ? ft_strdel(&h->op) : 0;
	(cs == 1) ? (h->op = ft_strdup("ss")) : 0;
	(cs == 2) ? (h->op = ft_strdup("rr")) : 0;
	(cs == 3) ? (h->op = ft_strdup("rrr")) : 0;
	return (cs);
}

void			ft_optimizator(t_ops *h, t_ops *d, int f, int x)
{
	t_ops		*ptr;

	while (f)
	{
		ptr = h;
		f = 0;
		d = ptr;
		while (ptr)
		{
			if ((x = ft_transform_operations(ptr, 0)) != 0)
			{
				f = 1;
				(x == 4 || x == 5 || x == 6) ? (d->next = ptr->next->next)
					: (d = ptr->next);
				(x == 4 || x == 5 || x == 6) ? (free(ptr->next->op)) :
					(ptr->next = ptr->next->next);
				(x == 4 || x == 5 || x == 6) ? (free(ptr->op)) : (free(d->op));
				(x == 4 || x == 5 || x == 6) ? (free(ptr->next)) : (free(d));
				(x == 4 || x == 5 || x == 6) ? (free(ptr)) : 0;
				(x == 4 || x == 5 || x == 6) ? (ptr = d) : 0;
			}
			d = ptr;
			ptr = ptr->next;
		}
	}
}
