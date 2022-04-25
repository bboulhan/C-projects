/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:10:28 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/19 20:28:59 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	read_line_2(t_stack **x, t_stack **y, char *line)
{
	t_stack	*a;
	t_stack	*b;

	a = *x;
	b = *y;
	if (!ft_strncmp(line, "pb\n", 3))
		push_a_bonus(&a, &b);
	else if (!ft_strncmp(line, "sb\n", 3))
		b = swap_b_bonus(b);
	else if (!ft_strncmp(line, "rb\n", 3))
		b = rotate_b_bonus(b);
	else if (!ft_strncmp(line, "rrb\n", 4))
		b = reverse_rotate_b_bonus(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr_bonus(&a, &b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr_bonus(&a, &b);
	else
		return (0);
	*x = a;
	*y = b;
	return (1);
}

int	read_line(t_stack **x, t_stack **y, char *line)
{
	t_stack	*a;
	t_stack	*b;

	a = *x;
	b = *y;
	if (!ft_strncmp(line, "sa\n", 3))
		a = swap_a_bonus(a);
	else if (!ft_strncmp(line, "ra\n", 3))
		a = rotate_a_bonus(a);
	else if (!ft_strncmp(line, "rra\n", 4))
		a = reverse_rotate_a_bonus(a);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss_bonus(&a, &b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_b_bonus(&b, &a);
	else if (read_line_2(&a, &b, line) == 0)
		return (0);
	*x = a;
	*y = b;
	return (1);
}

void	read_instructions(t_stack **x, t_stack **y)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;

	a = *x;
	b = *y;
	line = get_next_line(0);
	while (line)
	{
		if (read_line(&a, &b, line) == 0 && line)
		{
			write (1, "Error\n", 6);
			clean_stack_bonus(&a, &b);
			free(line);
			exit(0);
		}
		free(line);
		line = get_next_line(0);
	}
	*x = a;
	*y = b;
}

void	calcul(t_stack *x, t_stack *b)
{
	int	y;

	if (!x)
		return ;
	y = x -> content;
	x = x -> next;
	while (x)
	{
		if (y < x -> content)
			y = x -> content;
		else
		{
			write (1, "KO\n", 3);
			return ;
		}
		x = x -> next;
	}
	if (!b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		j;

	j = 0;
	b = NULL;
	args = NULL;
	if (ac <= 1)
		return (0);
	args = join_element(ac, av);
	while (args[j])
		j++;
	check(args);
	a = put_value(args, 0);
	f1_free(args, j);
	read_instructions(&a, &b);
	calcul(a, b);
	clean_stack_bonus(&a, &b);
	return (0);
}
