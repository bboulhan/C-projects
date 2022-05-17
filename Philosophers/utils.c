/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:52:37 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/18 19:52:57 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	char		*c;
	int			k;
	int			m;

	c = (char *)str;
	m = 1;
	k = 0;
	while (*c == ' ' || *c == '\n'
		|| *c == '\t' || *c == '\r'
		|| *c == '\f' || *c == '\v' )
	{
		c++;
	}
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			m = m * -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		k = (*c - 48) + k * 10;
		c++;
	}
	return ((k * m));
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

void	ft_usleep(int time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	while ((useconds_t)(get_time(start) * 1000 < time))
		usleep(1);
}

int	get_time(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000 + end.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000));
}

int	ft_error(int Er)
{
	if (Er == 1)
		printf("arguments error\ncheck your arguments\n");
	else
		printf("Error\n");
	return (1);
}
