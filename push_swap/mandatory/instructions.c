/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:48:54 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/19 19:27:31 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_a(t_stack *x, int n)
{
	t_stack	*y;
	t_stack	*z;

	if (!x || !x->next)
		return (x);
	y = x -> next;
	z = y -> next;
	y -> next = x;
	x -> next = z;
	if (n == 1)
		write (1, "sa\n", 3);
	return (y);
}

t_stack	*rotate_a(t_stack *x, int n)
{
	t_stack	*y;
	t_stack	*z;

	if (!x || !x->next)
		return (x);
	y = x -> next;
	z = ft_lstlast(x);
	z -> next = x;
	x -> next = NULL;
	if (n == 1)
		write (1, "ra\n", 3);
	return (y);
}

void	push_a(t_stack **a, t_stack **b, int n)
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
	if (n == 1)
		write (1, "pb\n", 3);
}

t_stack	*reverse_rotate_a(t_stack *x, int n)
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
	if (n == 1)
		write (1, "rra\n", 4);
	return (k);
}

void	ss(t_stack **k, t_stack **p, int n)
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
	if (n == 1)
		write(1, "ss\n", 3);
}
