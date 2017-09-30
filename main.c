/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:41:59 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:42:00 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_exe(t_fract *fractal)
{
	if (fractal->type == 1)
		mandelbrot(fractal);
	if (fractal->type == 2)
		julia(fractal);
	if (fractal->type == 3)
		burning(fractal);
}

int			ft_loop(t_fract *fractal)
{
	ft_move(fractal);
	ft_exe(fractal);
	return (0);
}

void		ft_set_arg(char *arg, t_fract *fractal)
{
	if (ft_strcmp(arg, "Mandelbrot") == 0)
		fractal->type = 1;
	else if (ft_strcmp(arg, "Julia") == 0)
		fractal->type = 2;
	else if (ft_strcmp(arg, "Burningship") == 0)
		fractal->type = 3;
	else
		ft_bad_arg();
}

int			main(int argc, char **argv)
{
	t_fract			*fractal;

	if (argc != 2)
		ft_error();
	if ((fractal = (t_fract*)malloc(sizeof(t_fract))) == NULL)
		ft_error();
	ft_set_arg(argv[1], fractal);
	fractal->data = ft_create();
	ft_base_fractale(fractal);
	mlx_loop_hook(fractal->data->mlx, ft_loop, fractal);
	mlx_expose_hook(fractal->data->mlx_window, my_expose_hook, fractal);
	mlx_hook(fractal->data->mlx_window, 2, 1L << 0, my_key_press, fractal);
	mlx_hook(fractal->data->mlx_window, 3, 1L << 1, my_key_release, fractal);
	mlx_hook(fractal->data->mlx_window, 6, (1L << 6), mouse_move, fractal);
	mlx_hook(fractal->data->mlx_window, 17, 0, ft_exit_cross, fractal);
	mlx_mouse_hook(fractal->data->mlx_window, my_mouse_hook, fractal);
	ft_exe(fractal);
	mlx_loop(fractal->data->mlx);
	return (0);
}
