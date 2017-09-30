/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:39:35 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/30 20:39:36 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	if (key == 1 || key == 8)
		ft_switch(key, fractal);
	if (key == 15)
		ft_base_fractale(fractal);
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
