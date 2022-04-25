/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:14:19 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/22 18:40:54 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	f(unsigned int i, char *c)
{
	c[i] = c[i];
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s)
	{	
		j = ft_strlen(s);
		while (*s)
		{
			f(i, s);
			i++;
			s++;
			k++;
		}
		s = s - k;
	}
}
