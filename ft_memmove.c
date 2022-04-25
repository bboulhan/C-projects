/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:01:06 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/18 12:16:51 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)dest;
	d = (char *)src;
	if (src != NULL || dest != NULL)
	{
		if (s > d)
		{
			while (n--)
				*(s + n) = *(d + n);
		}
		else
		{
			while (n--)
			{
				*s = *d;
				s++;
				d++;
			}
		}
	}
	return (dest);
}
