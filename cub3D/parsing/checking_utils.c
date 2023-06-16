/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:42:47 by bboulhan          #+#    #+#             */
/*   Updated: 2022/09/28 23:40:00 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_elem(char *line, t_map *map)
{
	if (!ft_strncmp(line, "NO ", 3))
		map->no++;
	else if (!ft_strncmp(line, "SO ", 3))
		map->so++;
	else if (!ft_strncmp(line, "WE ", 3))
		map->we++;
	else if (!ft_strncmp(line, "EA ", 3))
		map->ea++;
	else if (!ft_strncmp(line, "F ", 2))
		map->fc++;
	else if (!ft_strncmp(line, "C ", 2))
		map->cc++;
	else
		return (0);
	return (1);
}

int	check_elem_2(char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
		return (1);
	else if (!ft_strncmp(line, "SO ", 3))
		return (2);
	else if (!ft_strncmp(line, "WE ", 3))
		return (3);
	else if (!ft_strncmp(line, "EA ", 3))
		return (4);
	else if (!ft_strncmp(line, "F ", 2))
		return (5);
	else if (!ft_strncmp(line, "C ", 2))
		return (6);
	else
		return (0);
}

void	set_info(char *line, t_map *map, char *s)
{
	if (check_elem_2(line) == 1)
		map->no_info = ft_strdup(s);
	else if (check_elem_2(line) == 2)
		map->so_info = ft_strdup(s);
	else if (check_elem_2(line) == 3)
		map->we_info = ft_strdup(s);
	else if (check_elem_2(line) == 4)
		map->ea_info = ft_strdup(s);
	else if (check_elem_2(line) == 5)
		map->f_info = ft_strdup(s);
	else if (check_elem_2(line) == 6)
		map->c_info = ft_strdup(s);
	free(s);
}

void	check_info(char *line, t_map *map)
{
	int		i;
	char	*s;

	i = 1;
	s = ft_calloc(1, 1);
	check_before(line);
	if (check_intruder_2(line) == 1)
		ft_error(2);
	if (check_elem_2(line) > 0)
	{
		while (line[++i])
		{
			if (line[i] == '.' || line[i] == '/' || check_elem_2(line) > 4)
			{
				while (line[i] && (line[i] != '\n' && line[i] != ' '))
					s = add_char(s, line[i++]);
			}
		}
		set_info(line, map, s);
	}
	else
		free(s);
}

void	check_walls_top_and_bottom(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_error(2);
	}
}
