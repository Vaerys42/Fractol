/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:50:10 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:50:13 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int a, t_fract *fractal)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = 0;
	g = 0;
	b = 0;
	if (a == fractal->co->max_ite)
		return (1);
	if (fractal->color == 1)
		r = (a * 5);
	if (fractal->color == 2)
		g = (a * 5);
	if (fractal->color == 3)
		b = (a * 5);
	c = (r << 16) + (g << 8) + b;
	return (c);
}

void			put_pxl(t_data *data, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * data->s_l);
	data->image_string[i] = c;
	data->image_string[++i] = c >> 8;
	data->image_string[++i] = c >> 16;
}
