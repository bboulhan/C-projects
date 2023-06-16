/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:21:09 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/28 23:41:45 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_before(char *str)
{
	int	i;

	i = 2;
	if (check_elem_2(str) == 0 || check_elem_2(str) == 5
		|| check_elem_2(str) == 6)
		return ;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '.' || str[i] == '/')
		{
			if (str[i] == '.' || str[i] == '/')
				return ;
		}
		else
			ft_error(5);
	}
}

void	check_space(char *str)
{
	int		i;
	int		j;
	int		x;
	char	*s;

	x = 0;
	i = -1;
	j = 0;
	s = ft_strdup(str);
	s = ft_strtrim(s, " ");
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			j++;
		else if ((s[i] > '9' || s[i] < '0') && j > 0)
			x++;
	}
	free(s);
	if (j > 1 && x > 0)
		ft_error(6);
}

void	remove_space(char *line)
{
	int	i;

	i = ft_strlen(line);
	if (line[i - 1] == ' ')
	{
		while (--i > 0)
		{
			if (line[i] != ' ')
			{
				line[i + 1] = 0;
				break ;
			}
		}
	}
}

int	check_intruder_2(char *line)
{
	static int	i = 0;

	if (line[0] == '\n')
		return (0);
	if (check_elem_2(line) != 0)
		i++;
	if (check_elem_2(line) == 0 && i < 6)
		return (1);
	return (0);
}
