/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:30:14 by bboulhan          #+#    #+#             */
/*   Updated: 2022/01/07 13:55:29 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	handler2(int num)
{
	(void)num;
	ft_putstr("the msg have been sent successfully");
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		y;

	if (ac == 3)
	{
		y = ft_atoi(av[1]);
		pid = y;
		convert_send(av[2], pid);
		while (1)
			signal(SIGUSR2, handler2);
	}
	else
		ft_putstr("oops it seems there is a problem");
	return (0);
}	
