/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:08:10 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/04 20:17:40 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_base_2(unsigned int nbr, char *str)
{
	long	z;
	char	*base;

	base = str;
	z = nbr;
	if (z >= 16)
	{
		ft_putnbr_base(z / 16, base);
		ft_putnbr_base(z % 16, base);
	}
	else
		ft_putchar(base[z]);
}

int	ft_putnbr_base(unsigned int n, char *str)
{
	long	k;
	int		j;

	k = n;
	ft_putnbr_base_2(n, str);
	j = 1;
	while (k >= 16)
	{
		k = k / 16;
		j++;
	}
	return (j);
}
