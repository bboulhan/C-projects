/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:55:07 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/04 16:24:48 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_p2(unsigned int x)
{
	if (x >= 10)
	{
		ft_putnbr_p2 (x / 10);
		ft_putnbr_p2 (x % 10);
	}
	else
		ft_putchar (x + '0');
}

int	ft_putnbr_p(unsigned int n)
{
	int		j;

	ft_putnbr_p2(n);
	j = 1;
	while (n >= 10)
	{
		n = n / 10;
		j++;
	}
	return (j);
}
