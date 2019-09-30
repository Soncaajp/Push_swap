/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:46:51 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 12:41:13 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void				ft_sleep(void)
{
	size_t				i;

	i = 0;
	while (i < 1000000000)
		i++;
	return ;
}

static int				ft_int_strlen(int num)
{
	int					len;
	unsigned int		tmp;

	len = 1;
	if (num < 0)
	{
		len = 2;
		tmp = -num;
	}
	else
		tmp = num;
	while (tmp >= 10)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

static void				ft_print_stack(t_stacks *src, int i, int len, int l)
{
	ft_putstr("\n\x1b[32m__Stack_A__|__Stack_B__\x1b[0m\n");
	len = (src->len_a > src->len_b) ? src->len_a : src->len_b;
	while (++i < len)
	{
		ft_putstr("\x1b[30m\x1b[47m");
		l = (i < src->len_a) ? (11 - ft_int_strlen(src->a[i])) : 0;
		while (l--)
			ft_putstr(" ");
		(i < src->len_a) ? (ft_putnbr(src->a[i])) : 0;
		(i >= src->len_a) ? (ft_putstr("           ")) : 0;
		ft_putstr("\x1b[0m\x1b[32m|\x1b[0m\x1b[37m\x1b[40m");
		l = (i < src->len_b) ? (11 - ft_int_strlen(src->b[i])) : 0;
		while (l--)
			ft_putstr(" ");
		(i < src->len_b) ? (ft_putnbr(src->b[i])) : 0;
		(i >= src->len_b) ? (ft_putstr("           ")) : 0;
		ft_putstr("\x1b[0m\n");
	}
	ft_putstr("\x1b[0m\n");
	ft_sleep();
}

int						main(int argc, char **argv)
{
	t_stacks			*checker;
	char				*src;

	checker = (t_stacks*)malloc(sizeof(t_stacks));
	checker->len_a = 0;
	checker->len_b = 0;
	(argc == 1 || argv[1][0] == '\0') ? ft_error_free(-1, checker) : 0;
	ft_create_stack(checker, argc - 1, &argv[1]);
	(!valid_dup(checker->a, checker->len_a)) ? ft_error_free(3, checker) : 0;
	src = NULL;
	while (get_next_line(0, &src) > 0)
	{
		ft_operation(checker, src);
		free(src);
		(checker->visualize == 1) ? (ft_putstr("          \e[4;35m")) : 0;
		(checker->visualize == 1) ? ft_putstr(src) : 0;
		(checker->visualize == 1) ? (ft_print_stack(checker, -1, 0, 0)) : 0;
		checker->number_of_ops++;
	}
	show_num_of_opr(checker->show_number_of_op, checker);
	(ft_final_check(checker->a, checker->len_a, checker->amount)) ?
		ft_putstr("\033[0;32mOK\n\e[0m") : ft_putstr("\033[0;31mKO\n\e[0m");
	ft_free(checker);
	return (0);
}
