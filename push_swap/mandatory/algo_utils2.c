/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:25:13 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/20 18:21:25 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_1(int n, int *d, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (n == d[i])
			return (i);
		i++;
	}
	return (-1);
}

void	send_a(t_stack **x, t_stack **y, int j)
{
	t_stack	*a;
	t_stack	*b;
	int		k;

	k = 0;
	a = *x;
	b = *y;
	while (ft_lstsize(a) > 3)
	{
		k = check_pos(a, min_num(a));
		if (k <= j / 2)
			while (min_num(a) != a -> content)
				a = rotate_a(a, 1);
		else
			while (min_num(a) != a -> content)
				a = reverse_rotate_a(a, 1);
		push_a(&a, &b, 1);
	}
	*x = a;
	*y = b;
}

void	algo_2(t_stack **x, t_stack **y)
{
	t_stack	*a;
	t_stack	*b;

	a = *x;
	b = *y;
	send_a(&a, &b, ft_lstsize(a));
	a = t_stack_with_3(a);
	send_t_stack_b(&a, &b);
	*x = a;
	*y = b;
}

void	rrr_2(t_stack **p)
{
	t_stack	*y;
	t_stack	*z;

	y = *p;
	if (y && y->next)
	{
		z = y -> next;
		while (z -> next != NULL)
		{
			y = y -> next;
			z = y -> next;
		}
		y -> next = NULL;
		z -> next = *p;
		*p = z;
	}
}

void	rrr(t_stack **k, t_stack **p, int n)
{
	t_stack	*y;
	t_stack	*z;

	y = *k;
	if (k && y->next)
	{
		z = y -> next;
		while (z -> next != NULL)
		{
		y = y -> next;
			z = y -> next;
		}
		y -> next = NULL;
		z -> next = *k;
		*k = z;
	}
	rrr_2(p);
	if (n == 1)
		write (1, "rrr\n", 4);
}
