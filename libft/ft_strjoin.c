/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:34:09 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/17 19:53:24 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	char	*y;
	char	*w;
	int		j;
	int		z;

	if (!s1 || !s2)
		return (NULL);
	y = (char *)s1;
	w = (char *)s2;
	z = ft_strlen(y);
	j = ft_strlen(w);
	x = malloc(sizeof(char) * (z + j) + 1);
	if (!x)
		return (NULL);
	x = ft_memcpy(x, y, z);
	x = ft_memcpy(x + z, w, j);
	x[j] = '\0';
	return (x - z);
}
