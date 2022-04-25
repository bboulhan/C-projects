/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:17:44 by bboulhan          #+#    #+#             */
/*   Updated: 2022/01/07 14:10:51 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minitalk.h"

pid_t	g_pid;

void	check_signal(pid_t y, int x, int rs, int n)
{
	if (g_pid != y)
	{	
		g_pid = y;
		x = 8;
		rs = 0;
		n = 0;
	}
}

void	handler(int sig, siginfo_t *siginfo, void *content)
{
	static int	x = 8;
	static int	n = 0;
	static int	rs = 0;

	(void)content;
	if (x == 0 && n == 8)
	{	
		ft_putchar(rs);
		rs = 0;
		x = 8;
		n = 0;
	}
	if (x == 1 && rs == 0)
	{
		//usleep(500);
		kill(siginfo->si_pid, SIGUSR2);
	}
	if (sig == SIGUSR1)
		rs = rs + ft_power(2, n);
	if (x == 8 && n == 0 && rs <= 1)
		g_pid = siginfo->si_pid;
	check_signal(siginfo->si_pid, x, rs, n);
	usleep(100);
	x--;
	n++;
}

int	main(void)
{
	struct sigaction	red;

	red.sa_sigaction = &handler;
	red.sa_flags = SA_SIGINFO;
	ft_putstr("the pid is : ");
	ft_putnbr (getpid());
	ft_putchar ('\n');
	while (1)
	{
		sigaction(SIGUSR1, &red, NULL);
		sigaction(SIGUSR2, &red, NULL);
		pause();
	}
	return (0);
}
