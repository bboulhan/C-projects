/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_send.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:19:14 by bboulhan          #+#    #+#             */
/*   Updated: 2022/01/07 14:03:03 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minitalk.h"

void	convert(int x, char *str)
{
	static int	p = 0;

	if (*str == 0)
		p = 0;
	if (x > 1)
	{
		convert(x / 2, str);
		convert(x % 2, str);
	}
	else
		str[p++] = x + 48;
}

void	send(pid_t y, char *str)
{
	int	j;
	int	k;

	j = 0;
	while (j < 8)
	{	
		k = ft_strlen(str) - j - 1;
		if (k >= 0 && str[k] == '1')
			kill(y, SIGUSR1);
		else
			kill(y, SIGUSR2);
		usleep(600);
		j++;
	}
}

void	convert_send(char *msg, pid_t y)
{
	char	*str;
	int		i;

	i = 0;
	while (msg[i] != 0)
	{
		str = ft_calloc(9, 1);
		convert(msg[i], str);
		send(y, str);
		free(str);
		i++;
	}
	str = ft_calloc(1, 1);
	send(y, str);
	free(str);
}
