/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:47:44 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/12 23:12:20 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	count_len_and_wid(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(3);
	map->len = ft_strlen(line);
	while (line)
	{
		map->wid++;
		free(line);
		line = get_next_line(fd);
	}
}

void	check_map2(char *path, t_map *map)
{
	char	*line;
	int		fd;
	char	*s;

	fd = open (path, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	line = get_next_line(fd);
	s = ft_strdup(line);
	check_walls(line);
	while (line)
	{
		free(s);
		s = ft_strdup(line);
		check_components_bonus(line, map);
		free(line);
		line = get_next_line(fd);
	}
	if (s[ft_strlen(s) - 1] == '\n')
	{
		free(s);
		ft_error(2);
	}
	check_walls(s);
	free(s);
}

void	check_map(char *path, t_map *map)
{
	count_len_and_wid(path, map);
	check_len(path, map);
	check_map2(path, map);
	if (map->e == 0 || map->p != 1 || map->c < 1)
		ft_error(2);
}
