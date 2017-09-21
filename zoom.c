
#include "fractol.h"

void	ft_zoom_in(int x, int y, t_fract *fractal)
{
	fractal->co->x = fractal->co->x + x / 5;
	fractal->co->y = fractal->co->y + y / 5;
	fractal->co->x = fractal->co->x * 1.2;
	fractal->co->y = fractal->co->y * 1.2;
	fractal->co->zoom = fractal->co->zoom * 1.2;
}

void	ft_zoom_out(int x, int y, t_fract *fractal)
{
	fractal->co->x = fractal->co->x - x / 5;
	fractal->co->y = fractal->co->y - y / 5;
	fractal->co->x = fractal->co->x / 1.2;
	fractal->co->y = fractal->co->y / 1.2;
	fractal->co->zoom = fractal->co->zoom / 1.2;
}