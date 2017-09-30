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
	fractal->co->x1 = (x - 300) / fractal->co->zoom;
	fractal->co->y1 = (y - 300) / fractal->co->zoom;
	fractal->co->zoom *= 1.1;
	fractal->co->max_ite *= 1.1;
}

void	ft_zoom_out(int x, int y, t_fract *fractal)
{
	fractal->co->x1 = (x - 300) / fractal->co->zoom;
	fractal->co->y1 = (y - 300) / fractal->co->zoom;
	fractal->co->zoom /= 1.1;
	fractal->co->max_ite /= 1.1;
}
