/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:49:49 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/18 21:49:41 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_index(t_stack *b, int n)
{
	int		k;
	int		y;

	k = top_num(b);
	while (b)
	{
		y = b -> content;
		if (n < y && y <= k)
			k = y;
		b = b -> next;
	}
	return (k);
}

int	check_pos(t_stack *b, int n)
{
	int	i;
	int	j;

	i = 0;
	while (b)
	{
		j = b -> content;
		if (j == n)
			return (i);
		i++;
		b = b -> next;
	}
	return (i);
}

void	put_elem(t_stack **b, int k, int j, int n)
{
	int		y;
	t_stack	*x;

	x = *b;
	y = x -> content;
	if (j >= ft_lstsize(x) / 2 && j != 0)
	{
		y = ft_lstlast(x)->content;
		while (k != y)
		{
			x = reverse_rotate_b(x, 1);
			y = ft_lstlast(x)->content;
		}
		if (n > k)
			x = reverse_rotate_b(x, 1);
	}
	else if (j < ft_lstsize(x) / 2 && j != 0)
	{
		while (k != y)
		{
			x = rotate_b(x, 1);
			y = x -> content;
		}
	}
	*b = x;
}

void	edit_b(t_stack **a, t_stack **b, int n)
{
	int		k;
	int		j;
	t_stack	*y;
	t_stack	*x;

	x = *a;
	y = *b;
	j = 0;
	k = 0;
	if (y == NULL)
		push_a(&x, &y, 1);
	else if (y -> next == NULL && n < y -> content)
	{
		push_a(&x, &y, 1);
		y = swap_b(y, 1);
	}
	else
	{
		k = check_index(y, n);
		j = check_pos(y, k);
		put_elem(&y, k, j, n);
		push_a(&x, &y, 1);
	}
	*a = x;
	*b = y;
}

void	send_t_stack_b(t_stack **x, t_stack **y)
{
	t_stack	*a;
	t_stack	*b;

	a = *x;
	b = *y;
	while (b)
	{
		if (check_pos(b, top_num(b)) <= ft_lstsize(b) / 2)
		{
			while (top_num(b) != b -> content)
				b = rotate_b(b, 1);
		}
		else if (check_pos(b, top_num(b)) > ft_lstsize(b) / 2)
		{
			while (top_num(b) != b -> content)
				b = reverse_rotate_b(b, 1);
		}
		push_b(&b, &a, 1);
	}
	*x = a;
	*y = b;
}
