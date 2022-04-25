/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:20:29 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/04 21:32:09 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_2(int n)
{
	long	x;

	x = n;
	if (x < 0)
	{
		write (1, &"-", 1);
		x = x * (-1);
	}
	if (x >= 10)
	{
		ft_putnbr_2 (x / 10);
		ft_putnbr_2 (x % 10);
	}
	else
		ft_putchar (x + '0');
}

int	ft_putnbr(int n)
{
	long	k;
	int		j;

	k = n;
	ft_putnbr_2(n);
	j = 1;
	if (k < 0)
	{
		k = k * -1;
		j++;
	}
	while (k >= 10)
	{
		k = k / 10;
		j++;
	}
	return (j);
}
