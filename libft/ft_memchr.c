/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:15:13 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 09:15:54 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)str;
	while (n--)
	{
		if ((unsigned char)c == *d)
			return (d);
		d++;
	}
	return (NULL);
}
