/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:38:47 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/18 21:30:52 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	char		*c;
	long long	k;
	int			m;

	c = (char *)str;
	m = 1;
	k = 0;
	while (*c == ' ' || *c == '\n'
		|| *c == '\t' || *c == '\r'
		|| *c == '\f' || *c == '\v' )
		c++;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			m = m * -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		k = (*c - 48) + k * 10;
		c++;
	}
	if (k * m > 2147483647 || k * m < -2147483648)
		ft_error(2);
	return ((int)(k * m));
}

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

t_stack	*choice_2(t_stack *a)
{
	t_stack	*x;
	t_stack	*y;

	x = a -> next;
	y = x -> next;
	if (a -> content > x -> content && a ->content < y -> content)
		a = swap_a(a, 1);
	else if (a -> content < x -> content && a ->content > y -> content)
		a = reverse_rotate_a(a, 1);
	else
	{
		if (x ->content > y -> content)
		{
			a = rotate_a(a, 1);
			a = swap_a(a, 1);
		}
		else
			a = rotate_a(a, 1);
	}
	return (a);
}

t_stack	*t_stack_with_3(t_stack *a)
{
	t_stack	*x;
	t_stack	*y;

	x = a -> next;
	y = x -> next;
	if (a->content < x->content && x->content > y->content
		&& a->content < y->content)
	{
		a = reverse_rotate_a(a, 1);
		a = swap_a(a, 1);
	}
	else if (a -> content > x ->content || a -> content > y -> content)
		a = choice_2(a);
	return (a);
}
