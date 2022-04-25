/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:08:20 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/22 12:56:19 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	i = 0;
	x = (unsigned char *)s1;
	y = (unsigned char *)s2;
	if (x != NULL || y != NULL)
	{
		while ((x[i] != '\0' || y[i] != '\0')
			&& i != n)
		{
			if (x[i] != y[i])
				return (x[i] - y[i]);
			i++;
		}
	}
	return (0);
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

void	rrr_bonus(t_stack **k, t_stack **p)
{
	t_stack	*y;
	t_stack	*z;

	y = *k;
	if (y && y->next)
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
}

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
