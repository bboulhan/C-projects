/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:04:38 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/22 16:45:20 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*d;
	int		k;

	d = (char *)s;
	k = ft_strlen(d) + 1;
	while (k > 0)
	{
		if ((char)c == *d)
		{
			return (d);
		}
		d++;
		k--;
	}
	return (NULL);
}
