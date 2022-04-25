/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:03:58 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/06 21:10:32 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f2_print(char c, va_list args)
{
	int	j;

	j = 0;
	if (c == 'c')
		j = ft_putchar(va_arg(args, int));
	else if (c == 's')
		j = ft_putstr(va_arg(args, char *));
	else if (c == 'd')
		j = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		j = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		j = ft_putnbr_p(va_arg(args, unsigned int));
	else if (c == 'x')
		j = ft_putnbr_base(va_arg(args, unsigned int), HEXA);
	else if (c == 'X')
		j = ft_putnbr_base(va_arg(args, unsigned int), HEXAD);
	else if (c == 'p')
		j = pointer(va_arg(args, unsigned long int), HEXA);
	else
	{
		ft_putchar(c);
		j++;
	}
	return (j);
}
