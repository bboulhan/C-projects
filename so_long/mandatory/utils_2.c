/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:58:59 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/08 21:59:10 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("Error\ninvalid extensions\n");
	else if (i == 2)
		ft_putstr("Error\ninvalid map, check your map\n");
	else if (i == 3)
		ft_putstr("Error\nyour file is not exist\n");
	else if (i == 4)
		ft_putstr("Error\ninvalid parametre\n");
	exit(0);
}

void	check_exten(char *path)
{
	char	*exten;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	exten = ft_strrchr(path, '.');
	if (!exten || ft_strlen(exten) != 4)
		ft_error(1);
	if (ft_strncmp(exten, ".ber", 4))
		ft_error(1);
}

void	set_map2(char *path, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(3);
	line = get_next_line(fd);
	while (line)
	{
		map->table[i] = ft_strdup(line);
		if (line[ft_strlen(line) - 1] == '\n')
			map->table[i][ft_strlen(line) - 1] = 0;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map->table[i] = 0;
}

void	set_map(char *path, t_map *map)
{
	int	i;

	i = 0;
	map->table = malloc(sizeof(char **) * map->wid + 1);
	if (!(map->table))
		free_map(map);
	set_map2(path, map);
}

void	put_values(t_map *map)
{
	map->table = NULL;
	map->len = 0;
	map->wid = 0;
	map->e = 0;
	map->c = 0;
	map->p = 0;
	map->s = 0;
	map->n = 0;
	map->move = 0;
	map->cord_x = 0;
	map->cord_y = 0;
}
