/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:46:33 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/15 20:46:34 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *sum(void *ptr)
{

    int *x;
    x = ptr;
	*x *= *x;
	ptr = (void *)x;
    printf("%d\n", *x);

	return 0;
}

void    *multi(void *ptr)
{

    int *y;
    y = ptr;
	*y = *y * *y;
	ptr = (void *) y; 
    printf("%d\n", *y);
	return 0; 
}

int main()
{
    pthread_t p1, p2;
    int i, j;


    i = 5;
    j = 4;
    int x, y;
    x = pthread_create(&p1, NULL, &sum, (void *) &i);
    y = pthread_create(&p2, NULL, &multi, (void *) &j);
    pthread_join(p1, NULL);
    //pthread_join(p2, NULL);
    printf("%d\t%d\n%d\t%d\n", i, x, j, y);
    
    return 0;
}
