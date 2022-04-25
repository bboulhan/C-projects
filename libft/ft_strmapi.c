/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:57:13 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 16:03:32 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	f1(unsigned int i, char c)
{
	i = (unsigned int)i;
	return (c);
}

char	*ft_strmapi(char const *s, char (*f1)(unsigned int, char))
{
	char	*x;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	x = malloc(ft_strlen((char *)s) + 1);
	if (!x)
		return (NULL);
	while (s[i])
	{
		x[i] = f1(i, s[i]);
		i++;
	}
	x[i] = '\0';
	return (x);
}
