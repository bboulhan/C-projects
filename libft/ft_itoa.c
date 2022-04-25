/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:11:01 by bboulhan          #+#    #+#             */
/*   Updated: 2021/11/17 12:41:02 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	my_check(long k)
{
	int	j;

	j = 1;
	if (k < 0)
	{
		k = k * -1;
		j++;
	}
	while (k >= 10)
	{
		k = k / 10;
		j++;
	}
	return (j);
}

char	*my_print(char *str, long l, int j)
{
	int		k;
	char	*num;

	num = "0123456789";
	k = 1;
	if (l < 0)
	{
		str[0] = '-';
		l = l * -1;
		k = 2;
	}
	while (j >= k)
	{
		str[j - 1] = num[l % 10];
		l = l / 10;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		j;
	long	l;
	char	*str;

	l = n;
	j = my_check(l);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	str[j] = '\0';
	str = my_print(str, l, j);
	return (str);
}
