/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:01:23 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/18 21:57:35 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*put_value(char **av, int i)
{
	t_stack	*x;
	t_stack	*new;

	new = NULL;
	x = ft_lstnew(ft_atoi(av[i]));
	i++;
	while (av[i])
	{
		new = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&x, new);
		i++;
	}
	return (x);
}

int	min_num(t_stack *x)
{
	int	y;

	y = x -> content;
	while (x)
	{
		if (y > x -> content)
			y = x -> content;
		x = x -> next;
	}
	return (y);
}

int	top_num(t_stack *x)
{
	int	y;

	y = x -> content;
	while (x)
	{
		if (y < x -> content)
			y = x -> content;
		x = x -> next;
	}
	return (y);
}

int	pos_index(t_stack *x, int k)
{
	int	j;

	j = 0;
	while (x)
	{
		if (k > x -> content)
			j++;
		x = x -> next;
	}
	return (j);
}

int	*put_position(t_stack *x)
{
	int		*pos;
	int		y;
	t_stack	*z;

	z = x;
	pos = malloc(ft_lstsize(x));
	while (x)
	{
		y = pos_index(z, x -> content);
		pos[y] = x -> content;
		x = x -> next;
	}
	return (pos);
}
