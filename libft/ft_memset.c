/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:21:20 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/12 13:25:36 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//#include "libft.h"

void	*ft_memset(void *str, int c, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n--)
	{
		*ptr = c;
		ptr++;
	}
	return (str);
}
