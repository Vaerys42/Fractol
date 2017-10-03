/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:38:58 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:39:00 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_exit_cross(t_fract *fractal)
{
	mlx_destroy_image(fractal->data->mlx, fractal->data->mlx_image);
	system("killall afplay");
	exit(EXIT_SUCCESS);
	return (0);
}

void		ft_switch(int key, t_fract *fractal)
{
	if (key == 1)
	{
		fractal->type++;
		if (fractal->type >= 4)
			fractal->type = 1;
		ft_base_fractale(fractal);
	}
	else
	{
		fractal->color++;
		if (fractal->color >= 7)
			fractal->color = 1;
	}
	ft_exe(fractal);
}

int			my_mouse_hook(int key, int x, int y, t_fract *fractal)
{
	if (key == 4)
		ft_zoom_in(x, y, fractal);
	if (key == 5)
		ft_zoom_out(x, y, fractal);
	ft_exe(fractal);
	return (0);
}

int			my_expose_hook(t_fract *fractal)
{
	mlx_destroy_image(fractal->data->mlx, fractal->data->mlx_image);
	if ((fractal->data->mlx_image = mlx_new_image(fractal->data->mlx,
	IMG_X, IMG_Y)) == NULL)
		ft_error();
	if ((fractal->data->image_string =
	mlx_get_data_addr(fractal->data->mlx_image,
	&(fractal->data->bpp), &(fractal->data->s_l),
	&(fractal->data->endian))) == NULL)
		ft_error();
	ft_exe(fractal);
	return (0);
}

int			mouse_move(int x, int y, t_fract *fractal)
{
	if (fractal->type == 2)
		ft_modif_param(x, y, fractal);
	return (0);
}
