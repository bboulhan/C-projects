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

#include "so_long_bonus.h"

int	ft_close(t_map *map)
{
	free_map(map);
	exit(0);
	return (0);
}

void	put_img_bonus(t_map *map)
{
	int	i;

	i = 50;
	map->pic = mlx_init();
	map->window = mlx_new_window(map->pic, (map->len - 1) * 50,
			map->wid * 50, "so_long_bonus");
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
	map->enemy = mlx_xpm_file_to_image(map->pic, "./images/enemy.xpm",
			&i, &i);
	map->screen = mlx_xpm_file_to_image(map->pic, "./images/screen.xpm",
			&i, &i);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 13)
		move_up_bonus(map);
	else if (keycode == 0)
		move_left_bonus(map);
	else if (keycode == 2)
		move_right_bonus(map);
	else if (keycode == 1)
		move_down_bonus(map);
	else if (keycode == 53)
	{
		free_map(map);
		mlx_destroy_window(map->pic, map->window);
		exit(0);
	}
	mlx_clear_window(map->pic, map->window);
	draw_bonus(map);
	return (0);
}

void	draw_2_bonus(t_map *map, int j, int i)
{
	char	*s;

	s = ft_itoa(map->move);
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
	else if (map->table[j][i] == 'N')
		mlx_put_image_to_window(map->pic, map->window, map->enemy,
			i * 50, j * 50);
	mlx_string_put(map->pic, map->window, 17, 15, 16777215, s);
	free(s);
}

void	draw_bonus(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	mlx_put_image_to_window(map->pic, map->window, map->screen,
		0, 0);
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
				draw_2_bonus(map, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}
