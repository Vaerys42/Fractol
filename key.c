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

int			my_mouse_hook(int key, int x, int y, t_fract *fractal)
{
	if (key == 4)
		ft_zoom_in(x, y, fractal);
	if (key == 5)
		ft_zoom_out(x, y, fractal);
	ft_exe(fractal);
	return (0);
}

void	ft_move(t_fract *fractal)
{
	if (fractal->move->right == 1)
		fractal->co->x1 += 0.05;
	if (fractal->move->left == 1)
		fractal->co->x1 -= 0.05;
	if (fractal->move->up == 1)
		fractal->co->y1 -= 0.05;
	if (fractal->move->down == 1)
		fractal->co->y1 += 0.05;
}

int		my_key_press(int key, t_fract *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->data->mlx, fractal->data->mlx_window);
		free(fractal);
		exit(1);
	}
	if (key == LEFT_KEY)
		fractal->move->left = 1;
	if (key == RIGHT_KEY)
		fractal->move->right = 1;
	if (key == UP_KEY)
		fractal->move->up = 1;
	if (key == DOWN_KEY)
		fractal->move->down = 1;
	return (0);
}

int		my_key_release(int key, t_fract *fractal)
{
	if (key == LEFT_KEY)
		fractal->move->left = 0;
	if (key == RIGHT_KEY)
		fractal->move->right = 0;
	if (key == UP_KEY)
		fractal->move->up = 0;
	if (key == DOWN_KEY)
		fractal->move->down = 0;
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
	if ((ft_strcmp(fractal->type, "Julia") == 0))
		ft_modif_param(x, y, fractal);
	return (0);
}
