/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:26:46 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/12 23:05:43 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*d;

	d = s;
	i = ft_strlen(s);
	while (*s && i)
	{
		i--;
		s++;
	}
	while (i <= (int)ft_strlen(d))
	{
		if (*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s--;
		i++;
	}
	return (NULL);
}

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

char	*ft_strdup(const char *source)
{
	char	*s;
	int		i;

	i = 0;
	while (source[i])
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (source[i] != '\0')
	{
		s[i] = source[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	ft_putnbr(int n)
{
	long	x;

	x = n;
	if (x < 0)
	{
		write (1, &"-", 1);
		x = x * (-1);
	}
	if (x >= 10)
	{
		ft_putnbr (x / 10);
		ft_putnbr (x % 10);
	}
	else
		ft_putchar (x + '0');
}

void	ft_putstr(char *s)
{
	int	i;
	int	k;

	i = 0;
	if (s)
	{
		k = ft_strlen(s);
		while (i < k)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}
