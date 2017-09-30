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

void		ft_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

void		ft_exe(t_fract *fractal)
{
	if ((ft_strcmp(fractal->type, "Mandelbrot")) == 0)
		mandelbrot(fractal);
	if ((ft_strcmp(fractal->type, "Julia") == 0))
		julia(fractal);
	if (ft_strcmp(fractal->type, "Burningship") == 0)
		burning(fractal);
}

void		ft_bad_arg(void)
{
	ft_putstr("Bad Parameters\nUse one of the following:\nMandelbrot\nJulia\n");
	exit(1);
}

int		ft_loop(t_fract *fractal)
{
	ft_move(fractal);
	ft_exe(fractal);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fract			*fractal;

	if (argc != 2)
		ft_error();
	if ((fractal = (t_fract*)malloc(sizeof(t_fract))) == NULL)
		ft_error();
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		fractal->type = ft_strdup("Mandelbrot");
	else if (ft_strcmp(argv[1], "Julia") == 0)
		fractal->type = ft_strdup("Julia");
	else if (ft_strcmp(argv[1], "Burningship") == 0)
		fractal->type = ft_strdup("Burningship");
	else
		ft_bad_arg();
	fractal->data = ft_create();
	ft_base_fractale(fractal);
	mlx_loop_hook(fractal->data->mlx, ft_loop, fractal);
	mlx_expose_hook(fractal->data->mlx_window, my_expose_hook, fractal);
	mlx_hook(fractal->data->mlx_window, 2, 1L << 0, my_key_press, fractal);
	mlx_hook(fractal->data->mlx_window, 3, 1L << 1, my_key_release, fractal);
	mlx_hook(fractal->data->mlx_window, 6, (1L << 6), mouse_move, fractal);
	//mlx_mouse_hook(fractal->data->mlx_window, my_mouse_hook, fractal);
	ft_exe(fractal);
	mlx_loop(fractal->data->mlx);
	return (0);
}
