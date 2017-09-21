
#include "fractol.h"

int 		mandelbrot_iter(t_base *co)
{
	int		i;

	i = -1;
	while (++i < co->max_ite)
	{
		co->tmp = co->z_r;
		co->z_r = co->z_r * co->z_r - co->z_i * co->z_i + co->c_r;
		co->z_i = 2 * co->z_i * co->tmp + co->c_i;
		if (co->z_r * co->z_r + co->z_i * co->z_i >= 4)
			return (i);
	}
	return (i);
}

void		mandelbrot(t_fract *fractal)
{
	unsigned int 	x;
	unsigned int 	y;
	unsigned int 	color;

	x = fractal->co->x;
	while (++x < IMG_X + fractal->co->x)
	{
		y = fractal->co->y;
		while (++y < IMG_Y + fractal->co->y)
		{
			fractal->co->z_r = 0;
			fractal->co->z_i = 0;
			fractal->co->c_r = x / fractal->co->zoom + fractal->co->x1;
			fractal->co->c_i = y / fractal->co->zoom + fractal->co->y1;
			color = get_color(mandelbrot_iter(fractal->co), fractal);
			put_pxl(fractal->data, x - fractal->co->x, y - fractal->co->y, color);
		}
	}
	mlx_put_image_to_window(fractal->data->mlx, fractal->data->mlx_window, fractal->data->mlx_image, 0, 0);
}