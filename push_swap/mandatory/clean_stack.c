/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:23:53 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/22 13:00:35 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack_a(t_stack **x)
{
	t_stack	*a;

	a = NULL;
	while ((*x))
	{
		a = *x;
		(*x) = (*x)->next;
		free(a);
	}
}

void	clean_stack(t_stack **x, t_stack **y, int *pos, char **args)
{
	int	i;

	i = 0;
	if (*x)
		clean_stack_a(x);
	if (*y)
		clean_stack_a(y);
	if (pos)
		free(pos);
	if (*args)
	{
		while (args[i])
			i++;
		f1_free(args, i);
	}
	exit(0);
}
