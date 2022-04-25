/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:07:17 by bboulhan          #+#    #+#             */
/*   Updated: 2022/04/08 20:08:25 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "mlx.h"

typedef struct s_map
{
	char	**table;
	int		len;
	int		wid;
	int		c;
	int		e;
	int		p;
	int		s;
	int		n;
	int		cord_x;
	int		cord_y;
	int		move;
	void	*pic;
	void	*window;
	void	*walls;
	void	*exit;
	void	*player;
	void	*collect;
	void	*space;
	void	*enemy;
	void	*screen;
}	t_map;

char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(int i);
void	check_exten(char *path);
void	count_len_and_wid(char *path, t_map *map);
void	check_map(char *path, t_map *map);
char	*ft_strdup(const char *source);
void	check_components(char *line, t_map *map);
void	check_len(char *path, t_map *map);
void	check_walls(char *line);
void	put_values(t_map *maps);
void	set_map(char *path, t_map *map);
void	draw(t_map *map);
void	move_up(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	free_map(t_map *map);
void	put_img(t_map *map);
int		key_hook(int keycode, t_map *map);
void	draw(t_map *map);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_close(t_map *map);
void	write_move(t_map *map);

#endif