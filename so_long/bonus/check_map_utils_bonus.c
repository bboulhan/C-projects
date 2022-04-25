/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:16:05 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/09 18:16:20 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			if (line[i] == '\n' && line[i + 1] == 0)
				return ;
			else
			{
				free(line);
				ft_error(2);
			}
		}
		i++;
	}
}

void	check_len(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	line = get_next_line(fd);
	while (line)
	{
		if ((int)ft_strlen(line) != map->len)
		{
			if ((int)ft_strlen(line) == map->len - 1
				&& line[ft_strlen(line) - 1] == '1')
			{
			}
			else
			{
				free(line);
				ft_error(2);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	check_comp2(char *line, int i)
{
	if (line[i - 1] == '\n' && (line[0] != '1' || line[i - 2] != '1'))
	{
		free(line);
		ft_error(2);
	}
}

void	check_2(char *line, int i, t_map *map)
{
	if (line[i] == 'N')
		map->n++;
	else if (line[i] == 'C')
		map->c++;
	else if (line[i] == 'P')
		map->p++;
	else if (line[i] == 'E')
		map->e++;
}

void	check_components_bonus(char *line, t_map *map)
{
	int	i;

	i = 1;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1'
			|| (line[i] == '\n' && !line[i + 1]))
		{
			if (line[i] == '0')
				map->s++;
		}
		else if (line[i] == 'C' || line[i] == 'N'
			|| line[i] == 'P' || line[i] == 'E')
			check_2(line, i, map);
		else
		{
			free(line);
			ft_error(2);
		}
		i++;
	}
	check_comp2(line, i);
}
