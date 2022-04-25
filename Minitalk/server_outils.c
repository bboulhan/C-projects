/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:47:05 by bboulhan          #+#    #+#             */
/*   Updated: 2022/01/07 13:47:07 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
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
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_power(int nb, int power)
{
	int	d;

	d = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	power = power - 2;
	while (power >= 0)
	{
		nb = nb * d;
		power--;
	}
	return (nb);
}
