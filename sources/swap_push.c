/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:45:06 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 15:00:48 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sort_three_el(t_stacks *ps,
		int *arr, int len, t_ops *head)
{
	while (!ft_check(arr, len))
	{
		if (arr[0] > arr[1])
			(arr[0] < arr[len - 1]) ? add_op(ps, &head, "sa") :
				add_op(ps, &head, "ra");
		else if (!ft_check(arr, len))
			(arr[0] > arr[len - 1]) ? add_op(ps, &head, "rra") :
				add_op(ps, &head, "ra");
	}
}

void				ft_sort_excludes(t_stacks *ps,
		t_ops *head, int stack)
{
	if (stack == 97)
	{
		(ps->len_a > 1 && ps->a[0] > ps->a[1]) ? add_op(ps, &head, "sa") : 0;
		if (ps->len_a > 2 && ps->a[1] > ps->a[2])
		{
			add_op(ps, &head, "ra");
			add_op(ps, &head, "sa");
			add_op(ps, &head, "rra");
		}
		(ps->len_a > 1 && ps->a[0] > ps->a[1]) ? add_op(ps, &head, "sa") : 0;
	}
	else
	{
		(ps->len_b > 1 && ps->b[0] < ps->b[1]) ? add_op(ps, &head, "sb") : 0;
		if (ps->len_b > 2 && ps->b[1] < ps->b[2])
		{
			add_op(ps, &head, "rb");
			add_op(ps, &head, "sb");
			add_op(ps, &head, "rrb");
		}
		(ps->len_b > 1 && ps->b[0] < ps->b[1]) ? add_op(ps, &head, "sb") : 0;
	}
}

void				ft_push_swap_b(t_stacks *ps,
		t_ops *head, int len, int i)
{
	int				med;
	int				rotate;
	int				push;

	(len <= 3) ? ft_sort_excludes(ps, head, 'b') : 0;
	if (len <= 3)
		return ;
	med = ft_med(ps->b, len, 'b');
	push = 0;
	rotate = 0;
	while (sort_by_med(ps->b, len - i, med, 'b') && i++ < len)
	{
		(ps->b[0] > med) ? push++ : rotate++;
		(ps->b[0] > med) ? add_op(ps, &head, "pa") : add_op(ps, &head, "rb");
	}
	ft_push_swap(ps, head, push, 0);
	if (rotate > (ps->len_b / 2) && ps->len_b > 3)
		while (rotate++ < ps->len_b)
			add_op(ps, &head, "rb");
	else if (ps->len_b > 3)
		while (rotate--)
			add_op(ps, &head, "rrb");
	ft_push_swap_b(ps, head, len - push, 0);
	while (push--)
		add_op(ps, &head, "pb");
}

void				ft_push_swap(t_stacks *ps,
		t_ops *head, int len, int i)
{
	int				med;
	int				push;
	int				rotate;

	(len <= 3) ? ft_sort_excludes(ps, head, 'a') : 0;
	if (len <= 3)
		return ;
	med = ft_med(ps->a, len, 'a');
	push = 0;
	rotate = 0;
	while (sort_by_med(ps->a, len - i, med, 'a') && i++ < len)
	{
		(ps->a[0] < med) ? push++ : rotate++;
		(ps->a[0] < med) ? add_op(ps, &head, "pb") : add_op(ps, &head, "ra");
	}
	if (rotate > (ps->len_a / 2) && ps->len_a > 3)
		while (rotate++ < ps->len_a)
			add_op(ps, &head, "ra");
	else if (ps->len_a > 3)
		while (rotate--)
			add_op(ps, &head, "rra");
	ft_push_swap(ps, head, len - push, 0);
	ft_push_swap_b(ps, head, push, 0);
	while (push--)
		add_op(ps, &head, "pa");
}

void				swap_push(t_stacks *push_swap)
{
	t_ops		*head;
	t_ops		*point;

	head = (t_ops*)malloc(sizeof(t_ops));
	head->op = NULL;
	head->next = NULL;
	push_swap->number_of_ops = 0;
	point = NULL;
	if (push_swap->len_a > 3)
		ft_push_swap(push_swap, head, push_swap->len_a, 0);
	else
		ft_sort_three_el(push_swap, push_swap->a, push_swap->len_a, head);
	ft_optimizator(head, point, 1, 0);
	ft_print(head, push_swap);
}
