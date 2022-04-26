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
#include <sys/time.h>
#include <time.h>

typedef struct s_sim
{
    pthread_mutex_t	**mutex;
    int     		time_to_eat;
    int     		time_to_die;
    int     		time_to_sleep;
    int     		number_of_philosophers;
    int     		cercle;
	char			*forks;
    int     		*i;
}   t_sim;

typedef struct s_philosof
{
    pthread_t *thread;
	int		philosof_number;
	int		eating_time;
	int		last_meal;
    int     fork;
	t_sim	*sim;
}	t_philosof;




int     check_args(int ac, char **av);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);
void    set_sim(char **av, t_sim *ph, int ac);
void	*ft_calloc(size_t num, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *source);
int	    set_philos(t_sim *ph);
void	put_values(t_sim *p);
int		ft_error(int Er);
unsigned int	    get_time();
int		check_place(char *forks, int i);


#endif
