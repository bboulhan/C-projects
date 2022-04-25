/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:09:25 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/27 14:48:23 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f1_free(char **str, int i)
{
	int	j;

	j = 0;
	while (str[j] && j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

int	f2_check(char *x, char c)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	if (*x == c)
	{
		while (*x == c && *x)
		{
			k--;
			x++;
		}
		return (k);
	}
	else if (*x != c)
	{
		while (*x != c && *x)
		{
			j++;
			x++;
		}
		return (j);
	}
	return (0);
}

int	f4(char *x, char c)
{
	int	k;
	int	j;

	j = 0;
	k = 0;
	while (*x != '\0')
	{
		if (*x == c)
		{
			if (j == 0)
			{
			}
			else if (*(x - 1) != c)
				k++;
		}
		x++;
		j++;
	}
	if (k == 0)
		return (1);
	if (*x == 0 && *(x - 1) != c)
		k++;
	return (k);
}

char	**f6_second_print(char **str, char *x, char c)
{
	int	i;
	int	d;

	i = 0;
	while (*x != '\0')
	{
		d = f2_check(x, c);
		if (d > 0)
		{
			str[i] = malloc(sizeof(char) * d + 1);
			if (!str[i])
				f1_free(str, i);
			str[i] = ft_memcpy(str[i], x, d);
			str[i][d] = 0;
			i++;
			x = x + d - 1;
		}
		else
			x = x + (d * (-1)) - 1;
		x++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	*x;
	char	**str;

	if (!s)
		return (NULL);
	x = (char *)s;
	str = malloc(sizeof(char **) * (f4(x, c) + 1));
	if (!str)
		return (NULL);
	str = f6_second_print(str, x, c);
	return (str);
}
