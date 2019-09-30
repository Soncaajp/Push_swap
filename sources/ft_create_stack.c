/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:33:06 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 15:18:07 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_free(t_stacks *checker)
{
	(checker->len_a > 0) ? free(checker->a) : 0;
	(checker->len_b > 0) ? free(checker->b) : 0;
	free(checker);
}

static int		ft_flag_checker(t_stacks *checker, int argc, char **elements)
{
	checker->show_number_of_op = 0;
	checker->visualize = 0;
	if (argc >= 3)
	{
		(!ft_strcmp(elements[0], "-n") || !ft_strcmp(elements[1], "-n")) ?
			checker->show_number_of_op = 1 : 0;
		(!ft_strcmp(elements[0], "-v") || !ft_strcmp(elements[1], "-v")) ?
			checker->visualize = 1 : 0;
	}
	else
	{
		(!ft_strcmp(elements[0], "-n")) ? checker->show_number_of_op = 1 : 0;
		(!ft_strcmp(elements[0], "-v")) ? checker->visualize = 1 : 0;
	}
	return (checker->show_number_of_op + checker->visualize);
}

int				count_numbers(char **elements, int argc)
{
	int			i;
	int			j;
	int			amount;

	i = -1;
	amount = 0;
	while (++i < argc)
	{
		j = 0;
		while (elements[i][j] != '\0')
		{
			if (ft_isdigit(elements[i][j]))
			{
				amount++;
				while (ft_isdigit(elements[i][j]) && elements[i][j] != '\0')
					j++;
			}
			if (elements[i][j] == '\0')
				break ;
			j++;
		}
	}
	return (amount);
}

static void		collect_array(t_stacks *checker, char **elements)
{
	int			i;
	int			j;
	int			k;
	char		**split_elems;

	i = -1;
	j = -1;
	while (i < checker->len_a)
	{
		if (i + 1 == checker->len_a)
			break ;
		split_elems = ft_strsplit(elements[++j], ' ');
		k = -1;
		while (split_elems[++k])
		{
			checker->a[++i] = ft_atoi_ssize(split_elems[k], checker);
			free(split_elems[k]);
		}
		free(split_elems);
	}
}

void			ft_create_stack(t_stacks *checker, int argc, char **elements)
{
	int			flags;

	if (count_numbers(elements, argc) > 0)
		checker->a = (int*)malloc(sizeof(int) * count_numbers(elements, argc));
	flags = ft_flag_checker(checker, argc, elements);
	checker->len_a = count_numbers(elements, argc);
	(!checker->len_a) ? ft_error_free(6, checker) : 0;
	checker->len_b = 0;
	checker->amount = checker->len_a;
	checker->number_of_ops = 0;
	collect_array(checker, (!flags) ? elements : &elements[flags]);
}
