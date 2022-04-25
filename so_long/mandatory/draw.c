/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:03:33 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/12 01:03:42 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_map *map)
{
	free_map(map);
	exit(0);
	return (0);
}

void	put_img(t_map *map)
{
	int	i;

	i = 50;
	map->pic = mlx_init();
	map->window = mlx_new_window(map->pic, (map->len - 1) * 50,
			map->wid * 50, "so_long");
	map->space = mlx_xpm_file_to_image(map->pic, "./images/space.xpm",
			&i, &i);
	map->collect = mlx_xpm_file_to_image(map->pic, "./images/collect.xpm",
			&i, &i);
	map->exit = mlx_xpm_file_to_image(map->pic, "./images/exit.xpm",
			&i, &i);
	map->player = mlx_xpm_file_to_image(map->pic, "./images/player.xpm",
			&i, &i);
	map->walls = mlx_xpm_file_to_image(map->pic, "./images/walls.xpm",
			&i, &i);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 13)
		move_up(map);
	else if (keycode == 0)
		move_left(map);
	else if (keycode == 2)
		move_right(map);
	else if (keycode == 1)
		move_down(map);
	else if (keycode == 53)
	{
		mlx_destroy_window(map->pic, map->window);
		free_map(map);
		exit(0);
	}
	mlx_clear_window(map->pic, map->window);
	draw(map);
	return (0);
}

void	draw_2(t_map *map, int j, int i)
{
	if (map->table[j][i] == 'P')
	{
		mlx_put_image_to_window(map->pic, map->window, map->player,
			i * 50, j * 50);
		map->cord_x = i;
				map->cord_y = j;
	}
	else if (map->table[j][i] == 'C')
		mlx_put_image_to_window(map->pic, map->window, map->collect,
			i * 50, j * 50);
	else if (map->table[j][i] == 'E')
		mlx_put_image_to_window(map->pic, map->window, map->exit,
			i * 50, j * 50);
}

void	draw(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->table[j])
	{
		while (map->table[j][i])
		{
			if (map->table[j][i] == '1')
				mlx_put_image_to_window(map->pic, map->window, map->walls,
					i * 50, j * 50);
			else if (map->table[j][i] == '0')
				mlx_put_image_to_window(map->pic, map->window, map->space,
					i * 50, j * 50);
			else
				draw_2(map, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}
