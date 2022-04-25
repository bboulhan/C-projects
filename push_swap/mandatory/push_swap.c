/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:26:30 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/19 16:24:32 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_1(t_stack *x)
{
	int	y;

	y = x -> content;
	x = x -> next;
	while (x)
	{
		if (y < x -> content)
			y = x -> content;
		else
			return (0);
		x = x -> next;
	}
	return (1);
}

t_stack	*stack_with_2(t_stack *x)
{
	t_stack	*a;
	t_stack	*y;

	a = x;
	y = a -> next;
	if (a -> content > y -> content)
		a = swap_a(a, 1);
	return (a);
}

void	algo(t_stack **x, t_stack **y, int *pos)
{
	t_stack	*a;
	t_stack	*b;

	a = *x;
	b = *y;
	if (calcul_1(a) == 1)
	{
	}
	else if (ft_lstsize(a) == 2)
		a = stack_with_2(a);
	else if (ft_lstsize(a) == 3)
		a = t_stack_with_3(a);
	else if (ft_lstsize(a) > 3 && ft_lstsize(a) <= 5)
		algo_2(&a, &b);
	else if (ft_lstsize(a) > 5 && ft_lstsize(a) <= 200)
		algorhitme(&a, &b, pos, 5);
	else
		algorhitme(&a, &b, pos, 10);
	*x = a;
	*y = b;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*pos;
	char	**args;

	b = NULL;
	if (ac <= 1)
		return (0);
	args = join_element(ac, av);
	check(args);
	a = put_value(args, 0);
	pos = put_position(a);
	algo(&a, &b, pos);
	clean_stack(&a, &b, pos, args);
	return (0);
}
