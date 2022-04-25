/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:08:25 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/22 12:58:33 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*swap_a_bonus(t_stack *x)
{
	t_stack	*y;
	t_stack	*z;

	if (!x || !x->next)
		return (x);
	y = x -> next;
	z = y -> next;
	y -> next = x;
	x -> next = z;
	return (y);
}

t_stack	*rotate_a_bonus(t_stack *x)
{
	t_stack	*y;
	t_stack	*z;

	if (!x || !x->next)
		return (x);
	y = x -> next;
	z = ft_lstlast(x);
	z -> next = x;
	x -> next = NULL;
	return (y);
}

void	push_a_bonus(t_stack **a, t_stack **b)
{
	t_stack	*y;
	t_stack	*x;

	x = *a;
	if (!x)
		return ;
	y = x -> next;
	if (*b == NULL)
		x -> next = NULL;
	else
		x -> next = *b;
	*a = y;
	*b = x;
}

t_stack	*reverse_rotate_a_bonus(t_stack *x)
{
	t_stack	*y;
	t_stack	*k;

	if (!x || !x->next)
		return (x);
	y = x;
	k = y -> next;
	while (k -> next != NULL)
	{
		y = y -> next;
		k = y -> next;
	}
	y -> next = NULL;
	k -> next = x;
	return (k);
}

void	ss_bonus(t_stack **k, t_stack **p)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*y;
	t_stack	*z;

	a = *k;
	b = *p;
	if (a && a->next)
	{
		y = a -> next;
		z = y -> next;
		y -> next = a;
		a -> next = z;
		*k = y;
	}
	if (b && b->next)
	{
		y = b -> next;
		z = y -> next;
		y -> next = b;
		b -> next = z;
		*p = y;
	}
}
