/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:38:02 by rhulk             #+#    #+#             */
/*   Updated: 2019/09/26 15:27:57 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>

typedef struct			s_stacks
{
	int					*a;
	int					*b;
	int					len_a;
	int					len_b;
	int					amount;
	int					visualize;
	int					show_number_of_op;
	unsigned int		number_of_ops;
}						t_stacks;

typedef struct			s_ops
{
	char				*op;
	struct s_ops		*next;
}						t_ops;

void					ft_swap_two_first(int *int_arr, int len);
void					ft_rotate_up(int *int_arr, int len);
void					ft_rotate_down(int *int_arr, int len);
void					ft_push_value_into_a(t_stacks *checker);
void					ft_push_value_into_b(t_stacks *checker);
void					ft_create_stack(t_stacks *checker,
		int argc, char **argv);
void					ft_operation(t_stacks *checker, char *str);
void					copy_values(int **res, int *array, int len);
void					add_value(int **t, int *src, int n);
int						ft_final_check(int *arr, int len, int amount);
int						ft_check(int *arr, int len);
void					add_op(t_stacks *ps, t_ops **head, char *src);
void					swap_push(t_stacks *push_swap);
void					ft_print(t_ops *head, t_stacks *ps);
int						*ft_copy(int *arr, int len);
void					quicksort(int *list, int low, int high, int i);
int						ft_med(int *arr, int len, int f);
int						sort_by_med(int *arr, int len, int med, int stack);
void					ft_push_swap(t_stacks *ps,
		t_ops *head, int len, int i);
void					ft_optimizator(t_ops *head,
		t_ops *delete, int f, int x);
int						ft_error_free(int n, t_stacks *ps);
int						ft_atoi_ssize(char *src, t_stacks *ps);
int						valid_dup(int *a, int len);
void					show_num_of_opr(int num, t_stacks *ps);
void					ft_free(t_stacks *checker);

#endif
