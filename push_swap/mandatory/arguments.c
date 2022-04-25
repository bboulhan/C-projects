/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:26:26 by bboulhan          #+#    #+#             */
/*   Updated: 2022/03/23 15:40:11 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1));
	ft_memcpy(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[i] = 0;
	free(s1);
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)dst;
	d = (char *)src;
	if (src != NULL || dst != NULL)
	{
		while (n--)
		{
			*s = *d;
			s++;
			d++;
		}
	}
	return (dst);
}

int	check_space(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 32)
			k++;
		i++;
	}
	if (k == i)
		return (0);
	return (1);
}

char	**join_element(int ac, char **av)
{
	char	*str;
	char	**args;
	int		i;

	i = 1;
	str = malloc(1);
	if (!str)
		return (0);
	while (i < ac)
	{
		if (!check_space(av[i]))
		{
			free(str);
			ft_error(0);
		}
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	args = ft_split(str, 32);
	free(str);
	return (args);
}
