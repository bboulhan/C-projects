/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:13:32 by aer-razk          #+#    #+#             */
/*   Updated: 2022/09/25 13:14:09 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3D.h"

double	dbt(double x1, double y1, double x0, double y0)
{
	return (sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
}

/*double	dbt(double y1, double y0, double angle)
{
	return ((y1 - y0) / sin(angle));
}*/

int	rgb_to_int(int opacity, int red, int green, int blue)
{
	return ((opacity * 16777216) + (red * 65536) + (green * 256) + blue);
}

void	shortdistance(t_mlxk *window)
{
	double	dh;
	double	dv;

	dh = dbt(window->xh, window->yh, window->x0, window->y0);
	dv = dbt(window->xv, window->yv, window->x0, window->y0);
	if (dh > dv)
		window->length = dv;
	else
		window->length = dh;
}

/*void	shortdistance(t_mlxk *window, double angle)
{
	double dh;
	double	dv;

	dh = dbt(window->yh, window->y0, angle);
	dv = dbt(window->yv, window->y0, angle);
	if (dh > dv)
		window->length = dv;
	else
		window->length = dh;
}*/

int	ft_exit(void *arg)
{
	(void)arg;
	exit(0);
}
