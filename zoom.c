/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:50:50 by kboucaud          #+#    #+#             */
/*   Updated: 2017/09/21 11:50:52 by kboucaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_in(int x, int y, t_fract *fractal)
{
	fractal->co->x2 = x;
	fractal->co->y2 = y;
	fractal->co->x1 = (x / fractal->co->zoom + fractal->co->x1) - ( x / (fractal->co->zoom * 1.3));
	fractal->co->y1 = (y / fractal->co->zoom + fractal->co->y1) - (y / (fractal->co->zoom * 1.3));
	fractal->co->zoom *= 1.3;
	fractal->co->max_ite++;
}

void	ft_zoom_out(int x, int y, t_fract *fractal)
{
	fractal->co->x1 = (x / fractal->co->zoom + fractal->co->x1) - (x / (fractal->co->zoom / 1.3));
	fractal->co->y1 = (y / fractal->co->zoom + fractal->co->y1) - (y / (fractal->co->zoom / 1.3));
	fractal->co->zoom /= 1.3;
	fractal->co->max_ite--;	
}
