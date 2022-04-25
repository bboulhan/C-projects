/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:27:27 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/26 22:07:57 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
