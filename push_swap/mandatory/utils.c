/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:33:44 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/18 22:07:32 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*x;

	x = malloc(sizeof(t_stack));
	if (!x)
		return (NULL);
	x -> content = content;
	x -> next = NULL;
	return (x);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*y;

	y = NULL;
	if (lst)
	{
		y = lst;
		while (y -> next != NULL)
			y = y -> next;
	}
	return (y);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*y;

	y = NULL;
	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		y = ft_lstlast(*lst);
		y -> next = new;
		new -> next = NULL;
	}
}

int	ft_lstsize(t_stack *lst)
{
	int		k;
	t_stack	*y;

	k = 0;
	if (lst)
	{
		y = lst;
		while (y != NULL)
		{
			y = y -> next;
			k++;
		}
		return (k);
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
