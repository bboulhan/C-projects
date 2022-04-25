/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:12:18 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/22 22:29:56 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	x;

	x = n;
	if (x < 0)
	{
		write (fd, &"-", 1);
		x = x * (-1);
	}
	if (x >= 10)
	{
		ft_putnbr_fd (x / 10, fd);
		ft_putnbr_fd (x % 10, fd);
	}
	else
		ft_putchar_fd (x + '0', fd);
}
