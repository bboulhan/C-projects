/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:59:41 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/04 23:25:50 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start (args, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != 0)
		{	
			i++;
			j = j + f2_print(input[i], args);
		}
		else
		{	
			ft_putchar(input[i]);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}

int main()
{
	ft_printf("%d",-5, o,y);
}