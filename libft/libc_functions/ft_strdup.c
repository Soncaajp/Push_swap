/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:40:45 by emedea            #+#    #+#             */
/*   Updated: 2019/09/26 14:47:58 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(str) + 1;
	copy = (char*)malloc(sizeof(char) * size);
	if (copy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(copy, str, size);
	return (copy);
}
