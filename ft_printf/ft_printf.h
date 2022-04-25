/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:38:20 by bboulhan          #+#    #+#             */
/*   Updated: 2021/12/07 15:38:24 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define HEXA "0123456789abcdef"
# define HEXAD "0123456789ABCDEF"

int	f2_print(char c, va_list args);
int	ft_printf(const char *input, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putnbr_p(unsigned int n);
int	ft_putnbr_base(unsigned int n, char *str);
int	ft_putstr(char *s);
int	pointer(unsigned long int k, char *str);

#endif
