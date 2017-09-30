/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:32:52 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:32:53 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data		*ft_create(void)
{
	t_data		*data;

	if ((data = (t_data*)malloc(sizeof(t_data))) == NULL)
		ft_error();
	if ((data->mlx = mlx_init()) == NULL)
		ft_error();
	if ((data->mlx_window = mlx_new_window(data->mlx, IMG_X, IMG_Y, "Fractol"))\
	== NULL)
		ft_error();
	if ((data->mlx_image = mlx_new_image(data->mlx, IMG_X, IMG_Y)) == NULL)
		ft_error();
	if ((data->image_string = mlx_get_data_addr(data->mlx_image, &(data->bpp),\
	&(data->s_l), &(data->endian))) == NULL)
		ft_error();
	return (data);
}

void		ft_move_ini(t_fract *fractal)
{
	fractal->move->right = 0;
	fractal->move->left = 0;
	fractal->move->up = 0;
	fractal->move->down = 0;
}

void		ft_base_fractale(t_fract *fractal)
{
	if ((fractal->co = (t_base*)malloc(sizeof(t_base))) == NULL)
		ft_error();
	if ((fractal->move = (t_move*)malloc(sizeof(t_move))) == NULL)
		ft_error();
	if (ft_strcmp(fractal->type, "Julia") == 0)
		ft_ini_julia(fractal);	
	else
	{
		fractal->co->x1 = -2.1;
		fractal->co->x2 = 0.6;
		fractal->co->y1 = -1.2;
		fractal->co->y2 = 1.2;
		fractal->co->c_r = 0;
		fractal->co->c_i = 0;
	}
	ft_move_ini(fractal);
	fractal->co->z_r = 0;
	fractal->co->z_i = 0;
	fractal->co->tmp = 0;
	fractal->co->zoom = 200;
	fractal->co->max_ite = MAX_ITE;
	fractal->old_x = 0;
	fractal->old_y = 0;
}
