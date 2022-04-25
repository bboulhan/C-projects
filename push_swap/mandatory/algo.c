/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:08:53 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/19 14:37:59 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_top(t_stack *a, int *pos, int start, int len)
{
	int		i;
	int		j;
	int		k;

	k = ft_lstsize(a);
	j = 0;
	i = 0;
	while (i < k)
	{
		while (j < len)
		{
			if (a ->content == pos[start + j])
				return (a -> content);
			j++;
		}
		i++;
		j = 0;
		a = a -> next;
	}
	return (-1);
}

int	check_bottom(t_stack *a, int *pos, int start, int len)
{
	int	i;
	int	j;
	int	k;
	int	y;

	y = ft_lstsize(a);
	k = -1;
	j = 0;
	i = 0;
	while (i < y)
	{
		while (j < len)
		{
			if (a -> content == pos[start + j])
			{
				k = a -> content;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
		a = a -> next;
	}
	return (k);
}

t_stack	*get_it(t_stack *a, int j, int k)
{
	if (j != k)
	{
		if (check_pos(a, j) <= ft_lstsize(a) - check_pos(a, k))
		{
			while (a -> content != j)
				a = rotate_a(a, 1);
		}
		else
			while (a -> content != k)
				a = reverse_rotate_a(a, 1);
	}
	else
	{
		if (check_pos(a, j) <= ft_lstsize(a) / 2)
			while (a->content != j)
				a = rotate_a(a, 1);
		else
			while (a -> content != j)
				a = reverse_rotate_a(a, 1);
	}
	return (a);
}

void	send_part(t_stack **x, t_stack **y, int *pos, int len)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		start;
	int		k;

	a = *x;
	b = *y;
	i = 0;
	if (!b)
		start = 0;
	else
		start = ft_lstsize(b);
	while (i < len)
	{
		k = check_bottom(a, pos, start, len);
		a = get_it(a, check_top(a, pos, start, len), k);
		edit_b(&a, &b, a ->content);
		i++;
	}
	*x = a;
	*y = b;
}

void	algorhitme(t_stack **x, t_stack **y, int *pos, int np)
{
	int		p;
	int		len;
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = *x;
	b = *y;
	p = 0;
	i = ft_lstsize(a);
	len = ft_lstsize(a) / np;
	while (a)
	{
		send_part(&a, &b, pos, len);
		p = p + len;
		if (p / len == np)
			len = i % np;
	}
	send_t_stack_b(&a, &b);
	*x = a;
	*y = b;
}
