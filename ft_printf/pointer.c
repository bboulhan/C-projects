/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:20:20 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/04 23:13:27 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_3(unsigned long int z, char *str)
{
	char	*base;

	base = str;
	if (z >= 16)
	{
		ft_putnbr_base_3(z / 16, base);
		ft_putnbr_base_3(z % 16, base);
	}
	else
		ft_putchar(base[z]);
}

int	pointer(unsigned long int k, char *str)
{
	long	j;

	j = 3;
	ft_putstr("0x");
	ft_putnbr_base_3(k, str);
	while (k >= 16)
	{
		k = k / 16;
		j++;
	}
	return (j);
}
