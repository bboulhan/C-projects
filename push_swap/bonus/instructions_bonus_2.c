/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:08:52 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/22 12:56:51 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*swap_b_bonus(t_stack *x)
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

t_stack	*rotate_b_bonus(t_stack *x)
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

void	push_b_bonus(t_stack **b, t_stack **a)
{
	t_stack	*y;
	t_stack	*x;

	x = *b;
	y = x -> next;
	if (!x)
		return ;
	if (*a == NULL)
		x -> next = NULL;
	else
		x -> next = *a;
	*b = y;
	*a = x;
}

t_stack	*reverse_rotate_b_bonus(t_stack *x)
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

void	rr_bonus(t_stack **k, t_stack **p)
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
		z = ft_lstlast(a);
		z -> next = a;
		a -> next = NULL;
		*k = y;
	}
	if (b && b-> next)
	{
		y = b -> next;
		z = ft_lstlast(b);
		z -> next = b;
		b -> next = NULL;
		*p = y;
	}
}
