/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:08:20 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 09:52:40 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	i = 0;
	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (x != NULL || y != NULL)
	{
		while ((x[i] != '\0' || y[i] != '\0')
			&& i != n)
		{
			if (x[i] != y[i])
				return (x[i] - y[i]);
			i++;
		}
	}
	return (0);
}
