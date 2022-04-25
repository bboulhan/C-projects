/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:06:42 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 15:41:58 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*d;

	d = s;
	i = ft_strlen(s);
	while (*s && i)
	{
		i--;
		s++;
	}
	while (i <= (int)ft_strlen(d))
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s--;
		i++;
	}
	return (NULL);
}
