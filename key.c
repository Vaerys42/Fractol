
#include "fractol.h"

void		ft_key_move(int key, t_fract *fractal)
{
	int		i;

	i = 50;
	if (key == 126 && fractal->co->y >= i)
		fractal->co->y = fractal->co->y - i;
	if (key == 125)
		fractal->co->y = fractal->co->y + i;
	if (key == 123 && fractal->co->x >= i)
		fractal->co->x = fractal->co->x - i;
	if (key == 124)
		fractal->co->x = fractal->co->x + i;
}

int			my_key_func(int key, t_fract *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->data->mlx, fractal->data->mlx_window);
		free(fractal);
		exit(1);
	}
	ft_key_move(key, fractal);
	ft_exe(fractal);
	return (0);
}

int			my_expose_hook(t_fract *fractal)
{
	mlx_destroy_image(fractal->data->mlx, fractal->data->mlx_image);
	if ((fractal->data->mlx_image = mlx_new_image(fractal->data->mlx, IMG_X, IMG_Y)) == NULL)
		ft_error();
	if ((fractal->data->image_string = mlx_get_data_addr(fractal->data->mlx_image, &(fractal->data->bpp), &(fractal->data->s_l), &(fractal->data->endian))) == NULL)
		ft_error();
	ft_exe(fractal);
	return (0);
}

int			my_mouse_hook(int key, int x, int y, t_fract *fractal)
{
	if (key == 5)
		ft_zoom_in(x, y, fractal);
	if (key == 4)
		ft_zoom_out(x, y, fractal);
	ft_exe(fractal);
	return (0);
}

int		mouse_move(int x, int y, t_fract *fractal)
{
	if ((ft_strcmp(fractal->type, "Julia") == 0))
		ft_modif_param(x, y, fractal);
		return (0);
}
