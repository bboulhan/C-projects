/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:22:33 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/16 22:23:38 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_sim
{
	pthread_mutex_t	**mutex;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				number_of_philosophers;
	int				all_meals;
	int				meals_left;
}	t_sim;

typedef struct s_philosof
{
	pthread_t		*thread;
	int				philosof_number;
	int				number_of_meals;
	struct timeval	death;
	t_sim			*sim;
}	t_philosof;

int		check_args(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	set_sim(char **av, t_sim *ph, int ac);
void	put_values(t_sim *p);
int		ft_error(int Er);
int		get_time(struct timeval start);
void	ft_usleep(int time);
void	put_values_2(t_sim *ph, t_philosof ***s);
void	*routine(void *arg);
int		manager(pthread_t *philo, t_philosof **p, t_sim *sim);

#endif
