/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:00:12 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/13 01:00:27 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	j;

	j = 0;
	while (map->table[j])
	{
		free(map->table[j]);
		j++;
	}
	free(map->table);
}

int	main(int ac, char **av)
{
	t_map	map;

	put_values(&map);
	if (ac != 2)
		ft_error(4);
	check_exten(av[1]);
	check_map(av[1], &map);
	set_map(av[1], &map);
	put_img_bonus(&map);
	draw_bonus(&map);
	mlx_hook(map.window, 2, 0, key_hook, &map);
	mlx_hook(map.window, 17, 0, ft_close, &map);
	mlx_loop(map.pic);
	return (0);
}
