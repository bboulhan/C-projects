
#include "philo.h"


float time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

int	get_time()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}


int main()
{
    struct timeval start;
    struct timeval end;

    printf("%d\n",get_time());
    // usleep(300);
    // gettimeofday(&end, NULL);
    // printf(" %d  \n", end.tv_usec - start.tv_usec);
}

