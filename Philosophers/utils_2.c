/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 00:29:08 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/19 00:29:21 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"  

void	ft_usleep(int time)
{
	struct timeval	start;
	struct timeval	end;
	
	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	while ((useconds_t )(end.tv_usec - start.tv_usec <= time))
		gettimeofday(&end, NULL);
}

int	ft_error(int Er)
{
	if (Er == 1)
		printf("arguments error\ncheck your arguments\n");
	else
		printf("Error\n");
	return (1);
}

int	get_time(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000 + end.tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000));
}

int	check_place(char *forks, int i)
{
	if (forks[i] == '1')
	{
		if (forks[i + 1])
		{
			if (forks[i + 1] == '1')
				return (i + 1);
		}
		else if (forks[0] == '1')
			return (0);
	}
	return (-1);
}