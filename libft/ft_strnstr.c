/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:17:48 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/23 02:06:03 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		k;
	size_t	i;

	k = 0;
	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while (i < len && i < ft_strlen(haystack))
	{
		while (haystack[i] != needle[k] && haystack[i] && needle[k] && i < len)
			i++;
		while (haystack[i] == needle[k] && haystack[i] && needle[k] && i < len)
		{
			i++;
			k++;
		}
		if (needle[k] == '\0')
			return ((char *) haystack + i - k);
		i = i - (k - 1);
		k = 0;
	}
	return (NULL);
}
