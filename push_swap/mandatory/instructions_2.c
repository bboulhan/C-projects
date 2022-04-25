/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:13:59 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/19 19:28:12 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap_b(t_stack *x, int n)
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
		write (1, "sb\n", 3);
	return (y);
}

t_stack	*rotate_b(t_stack *x, int n)
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
		write (1, "rb\n", 3);
	return (y);
}

void	push_b(t_stack **b, t_stack **a, int n)
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
	if (n == 1)
		write (1, "pa\n", 3);
}

t_stack	*reverse_rotate_b(t_stack *x, int n)
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
		write (1, "rrb\n", 4);
	return (k);
}

void	rr(t_stack **k, t_stack **p, int n)
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
	if (n == 1)
		write (1, "rr\n", 3);
}
