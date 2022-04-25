/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:19:33 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 09:18:52 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	i = 0;
	x = (unsigned char *)str1;
	y = (unsigned char *)str2;
	if (str1 != NULL || str2 != NULL)
	{
		while (n--)
		{
			if (*x != *y)
				return (*x - *y);
			y++;
			x++;
		}
	}
	return (0);
}
