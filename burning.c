/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:15:37 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:15:40 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			burning_ite(t_base *co)
{
	int		i;

	i = -1;
	while (++i < co->max_ite)
	{
		co->tmp = co->z_i;
		co->z_i = fabs((double)(co->z_r * co->z_i + co->z_r * co->z_i +\
		co->c_i));
		co->z_r = fabs((double)(co->z_r * co->z_r - co->tmp * co->tmp\
		+ co->c_r));
		if (co->z_r * co->z_r + co->z_i - co->z_i >= 4)
			return (i);
	}
	return (i);
}

void		burning(t_fract *fractal)
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		color;

	x = fractal->co->x;
	while (++x < IMG_X + fractal->co->x)
	{
		y = fractal->co->y;
		while (++y < IMG_Y + fractal->co->y)
		{
			fractal->co->c_r = x / fractal->co->zoom + fractal->co->x1;
			fractal->co->c_i = y / fractal->co->zoom + fractal->co->y1;
			fractal->co->z_r = fractal->co->c_r;
			fractal->co->z_i = fractal->co->c_i;
			color = get_color(burning_ite(fractal->co), fractal);
			put_pxl(fractal->data, x - fractal->co->x, y - fractal->co->y,\
			color);
		}
	}
	mlx_put_image_to_window(fractal->data->mlx, fractal->data->mlx_window,\
	fractal->data->mlx_image, 0, 0);
}
