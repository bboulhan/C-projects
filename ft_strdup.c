/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:20:30 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 09:49:26 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*s;
	int		i;

	i = 0;
	while (source[i])
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (source[i] != '\0')
	{
		s[i] = source[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
