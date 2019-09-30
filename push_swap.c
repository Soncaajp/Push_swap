/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:40:41 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 12:19:53 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int				main(int argc, char **argv)
{
	t_stacks	*push_swap;

	push_swap = (t_stacks*)malloc(sizeof(t_stacks));
	push_swap->len_a = 0;
	push_swap->len_b = 0;
	(argc == 1 || argv[1][0] == '\0') ? ft_error_free(2, push_swap) : 0;
	ft_create_stack(push_swap, argc - 1, &argv[1]);
	(!valid_dup(push_swap->a, push_swap->len_a)) ?
		ft_error_free(3, push_swap) : 0;
	if (ft_final_check(push_swap->a, push_swap->len_a, push_swap->amount))
		return (0);
	if (push_swap->len_a == 2)
	{
		ft_operation(push_swap, "sa");
		push_swap->number_of_ops++;
		ft_putstr("sa\n");
	}
	else if (push_swap->len_a > 2)
		swap_push(push_swap);
	show_num_of_opr(push_swap->show_number_of_op, push_swap);
	ft_free(push_swap);
	return (0);
}
