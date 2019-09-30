/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:51:01 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 15:27:22 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
			c == '\r' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

int				ft_atoi_ssize(char *src, t_stacks *ps)
{
	ssize_t		tmp;
	ssize_t		sign;

	tmp = 0;
	sign = 1;
	while (ft_isspace(*src))
		src++;
	if (*src == '-')
		sign = -1;
	if (*src == '-' || *src == '+')
		src++;
	(*src == '\0') ? ft_error_free(6, ps) : 0;
	while (ft_isdigit(*src))
	{
		tmp *= 10;
		tmp += *src - '0';
		src++;
	}
	if (*src != '\0' && *src != '-' && !ft_isdigit(*src))
		ft_error_free(3, ps);
	tmp = tmp * sign;
	if (tmp > 2147483647 || tmp < -2147483648)
		ft_error_free(4, ps);
	return ((int)tmp);
}

int				ft_error_free(int n, t_stacks *ps)
{
	if (n > 0)
	{
		ft_putstr("\033[0;31m");
		ft_putstr("Error\n");
	}
	(n == 1) ? ft_putstr("Invalid command\n") : 0;
	(n == 2) ? ft_putstr("Invalid number of arguments\n") : 0;
	(n == 3) ? ft_putstr("Invalid array\n") : 0;
	(n == 4) ? ft_putstr("Int overflow\n") : 0;
	ft_free(ps);
	exit(0);
	return (0);
}

static int		ft_check_operation(char *str)
{
	return (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb") ||
			!ft_strcmp(str, "ss") || !ft_strcmp(str, "pa")
			|| !ft_strcmp(str, "pb") ||
			!ft_strcmp(str, "ra") || !ft_strcmp(str, "rb")
			|| !ft_strcmp(str, "rr") ||
			!ft_strcmp(str, "rra") || !ft_strcmp(str, "rrb")
			|| !ft_strcmp(str, "rrr"));
}

void			ft_operation(t_stacks *c, char *str)
{
	if (!ft_check_operation(str))
		ft_error_free(1, c);
	(ft_strcmp(str, "sa") == 0) ? ft_swap_two_first(c->a, c->len_a) : 0;
	(ft_strcmp(str, "sb") == 0) ? ft_swap_two_first(c->b, c->len_b) : 0;
	(ft_strcmp(str, "ss") == 0) ? ft_swap_two_first(c->a, c->len_a) : 0;
	(ft_strcmp(str, "ss") == 0) ? ft_swap_two_first(c->b, c->len_b) : 0;
	(ft_strcmp(str, "pa") == 0) ? ft_push_value_into_a(c) : 0;
	(ft_strcmp(str, "pb") == 0) ? ft_push_value_into_b(c) : 0;
	(ft_strcmp(str, "ra") == 0) ? ft_rotate_up(c->a, c->len_a) : 0;
	(ft_strcmp(str, "rb") == 0) ? ft_rotate_up(c->b, c->len_b) : 0;
	(ft_strcmp(str, "rr") == 0) ? ft_rotate_up(c->a, c->len_a) : 0;
	(ft_strcmp(str, "rr") == 0) ? ft_rotate_up(c->b, c->len_b) : 0;
	(ft_strcmp(str, "rra") == 0) ? ft_rotate_down(c->a, c->len_a) : 0;
	(ft_strcmp(str, "rrb") == 0) ? ft_rotate_down(c->b, c->len_b) : 0;
	(ft_strcmp(str, "rrr") == 0) ? ft_rotate_down(c->a, c->len_a) : 0;
	(ft_strcmp(str, "rrr") == 0) ? ft_rotate_down(c->b, c->len_b) : 0;
}
