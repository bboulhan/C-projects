/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:11:06 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/20 09:48:09 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
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
