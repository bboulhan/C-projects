#include "philo.h"

void    *h(void *j)
{
    t_philo            *philos;
    static int        i = -1;
    int                c;
    struct timeval    start;
    struct timeval    end;

    philos = (t_philo *)j;
    i++;
    c = i;
    usleep(200 * (philos[c].n_philos - c + 1));
    gettimeofday(&start, NULL);
    while (1 && end.tv_usec - start.tv_usec < philos[c].t_die)
    {
        pthread_mutex_lock(&philos[c].mutex);
        if (c == philos[c].n_philos)
            pthread_mutex_lock(&philos[0].mutex);
        else
            pthread_mutex_lock(&philos[c + 1].mutex);
        gettimeofday(&start, NULL);
        printf("%d %d has taken a fork\n", start.tv_usec, c + 1);
        philos[c].n_forks++;
        gettimeofday(&start, NULL);
        printf("%d %d is eating\n", start.tv_usec, c + 1);
        usleep(philos[c].t_eat);
        pthread_mutex_unlock(&philos[c].mutex);
        if (c == philos[c].n_philos)
            pthread_mutex_unlock(&philos[0].mutex);
        else
            pthread_mutex_unlock(&philos[c + 1].mutex);
        if (philos[c].n_forks == 2)
        {
            gettimeofday(&start, NULL);
            printf("%d %d is sleeping\n", start.tv_usec, c + 1);
            philos[c].n_forks--;
            usleep(philos[c].t_sleep);
        }
        printf("%d is thinking\n", c + 1);
        gettimeofday(&end, NULL);
    }
    gettimeofday(&start, NULL);
    printf("%d %d is dead\n", start.tv_usec, c + 1);
    exit(1);
    return (j);
}