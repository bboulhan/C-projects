/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:00:55 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/13 01:01:48 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mandatory/so_long.h"

void	check_components_bonus(char *line, t_map *map);
void	put_img_bonus(t_map *map);
void	draw_bonus(t_map *map);
void	move_right_bonus(t_map *map);
void	move_up_bonus(t_map *map);
void	move_down_bonus(t_map *map);
void	move_left_bonus(t_map *map);
char	*ft_itoa(int n);

#endif