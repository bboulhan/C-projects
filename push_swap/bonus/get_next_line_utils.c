/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:49:50 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/15 19:17:38 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy2(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)dest;
	d = (char *)src;
	if (src != NULL || dest != NULL)
	{
		while (n--)
		{
			*s = *d;
			s++;
			d++;
		}
	}
	return (dest);
}

void	*ft_calloc2(size_t num, size_t size)
{
	char	*x;
	int		y;

	y = num * size;
	x = malloc(y);
	if (!x)
		return (NULL);
	while (y--)
		x[y] = 0;
	return (x);
}

char	*ft_strchr2(char *s, int c)
{
	unsigned char	*d;
	int				k;

	k = ft_strlen2(s) + 1;
	d = (unsigned char *)s;
	while (k--)
	{
		if ((unsigned char)c == *d)
		{
			d++;
			return ((char *) d);
		}
		d++;
	}
	return (NULL);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen2(s);
	if (start < i)
	{
		if ((i - start) < len)
			str = ft_calloc2(i - start + 1, 1);
		else
			str = ft_calloc2(len + 1, 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < len && s[start])
			str[i++] = s[start++];
		str[i] = 0;
		free(s);
		return (str);
	}
	free(s);
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen2(s1) + ft_strlen2(s2);
	s = ft_calloc2(i + 1, 1);
	if (!s)
		return (NULL);
	ft_memcpy2(s, s1, ft_strlen2(s1));
	ft_memcpy2(s + ft_strlen2(s1), s2, ft_strlen2(s2));
	s[i] = 0;
	free(s1);
	return (s);
}
