
#include "philo.h"

void	*test(void *arg)
{
	t_philosof	*p;
	static int i = 0;
	p = arg;
	while (1)
	{
		pthread_mutex_lock(p->sim->mutex[p->philosof_number]);
		printf("hey\t%d\n", i);
		i++;
		pthread_mutex_unlock(p->sim->mutex[1]);
	}
	return (NULL);
}

void	*test_2(void *arg)
{
	t_philosof	*p;
	static int i = 0;
	p = arg;
	usleep(10000);
	while (1)
	{
		pthread_mutex_lock(p->sim->mutex[p->philosof_number]);
		printf("ibra\t%d\n", i);
		i++;
		pthread_mutex_unlock(p->sim->mutex[0]);
	}
	return (NULL);
}