/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:14:14 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/22 14:10:18 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	clean_one_stack(t_stack **x)
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

void	clean_stack_bonus(t_stack **x, t_stack **y)
{
	if (*x)
		clean_one_stack(x);
	if (*y)
		clean_one_stack(y);
	return ;
}
