/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:37:00 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:38:18 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_ini_julia(t_fract *fractal)
{
	fractal->co->x1 = -1.4;
	fractal->co->x2 = 1.4;
	fractal->co->y1 = -1.4;
	fractal->co->y2 = 1.4;
	fractal->co->c_r = 0.285;
	fractal->co->c_i = 0.01;
}

void				ft_modif_param(int x, int y, t_fract *fractal)
{
	if ((x > fractal->old_x) || (y > fractal->old_y))
	{
		if (fractal->co->c_r <= 0.4)
			fractal->co->c_r += 0.005;
		fractal->old_x = x;
		fractal->old_y = y;
		julia(fractal);
	}
	if ((x < fractal->old_x) || (y < fractal->old_y))
	{
		if (fractal->co->c_r >= 0.2)
			fractal->co->c_r -= 0.005;
		fractal->old_x = x;
		fractal->old_y = y;
		julia(fractal);
	}
}

unsigned int		julia_iter(t_base *co)
{
	int		i;

	i = -1;
	while (++i < co->max_ite)
	{
		co->tmp = co->z_r;
		co->z_r = co->z_r * co->z_r - co->z_i * co->z_i + co->c_r;
		co->z_i = 2 * co->z_i * co->tmp + co->c_i;
		if (co->z_r * co->z_r + co->z_i * co->z_i >= 4)
			return (i);
	}
	return (i);
}

void				julia(t_fract *fractal)
{
	int				x;
	int				y;
	unsigned int	color;

	x = -1;
	while (++x < IMG_X)
	{
		y = -1;
		while (++y < IMG_Y)
		{
			fractal->co->z_r = x / fractal->co->zoom + fractal->co->x1;
			fractal->co->z_i = y / fractal->co->zoom + fractal->co->y1;
			color = get_color(julia_iter(fractal->co), fractal);
			put_pxl(fractal->data, x, y, color);
		}
	}
	mlx_put_image_to_window(fractal->data->mlx, fractal->data->mlx_window,
	fractal->data->mlx_image, 0, 0);
}
