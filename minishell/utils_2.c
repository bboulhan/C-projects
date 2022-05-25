/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:44:46 by bboulhan          #+#    #+#             */
/*   Updated: 2022/05/23 20:45:00 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	if (start < i)
	{
		if ((i - start) < len)
        	str = malloc(i - start + 1);
        else
			str = malloc(len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (i < len && s[start])
			str[i++] = s[start++];
		str[i] = 0;
		return (str);
	}
	str = malloc(1);
	str[0] = 0;
	return (str);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*y;

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

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*y;

	y = NULL;
	if (lst)
	{
		y = lst;
		while (y -> next != NULL)
			y = y -> next;
	}
	return (y);
}