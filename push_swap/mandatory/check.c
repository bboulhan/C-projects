/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 15:01:40 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/23 16:12:12 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int f)
{
	if (f == 1)
		write(1, "Error\n", 6);
	if (f == 0)
		write (1, "Error\n", 6);
	if (f == 2)
		write (1, "Error\n", 6);
	exit(0);
}

int	check_value(char **av, char *s, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_atoi(av[i]) == ft_atoi(s))
			return (0);
		i++;
	}
	return (1);
}

int	check_num(char *s)
{
	int	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '-' && s[i] != '+')
			return (0);
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] == 0)
				return (0);
			else if (s[i + 1] == '-' || s[i + 1] == '+')
				return (0);
			else if (i > 0 && s[i - 1] != 32)
				return (0);
		}
		i++;
	}
	return (1);
}

void	check(char **av)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (av[j])
		j++;
	while (i < j)
	{
		if (check_num(av[i]) == 0)
		{
			f1_free(av, j);
			ft_error(0);
		}	
		if (check_value(av, av[i], i) == 0)
		{
			f1_free(av, j);
			ft_error(0);
		}	
		i++;
	}
}
