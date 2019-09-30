/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:15:54 by emedea            #+#    #+#             */
/*   Updated: 2019/09/15 11:46:17 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	int			negative;
	long long	result;
	long long	temp;

	negative = 1;
	result = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' ||
	*str == '\r' || *str == '\n' || *str == '\f' || *str == '\v'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		temp = (result * 10) + (*str++ - '0');
		if (temp < -2147483648 || temp > 2147483647)
			return (0);
		result = temp;
	}
	return ((int)(result * negative));
}
