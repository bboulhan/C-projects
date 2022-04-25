/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:21:13 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/23 02:06:22 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize >= i && dstsize > 0)
	{
		while (src[j] && (i + j) < dstsize - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
		while (src[j])
			j++;
		return (i + j);
	}
	while (src[j])
		j++;
	return (j + dstsize);
}
