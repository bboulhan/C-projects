/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:17:03 by bboulhan          #+#    #+#             */
/*   Updated: 2022/01/07 14:12:18 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

void	ft_putstr(char *s);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_power(int nb, int power);
void	*ft_calloc(size_t num, size_t size);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	convert_send(char *msg, pid_t y);

#endif
