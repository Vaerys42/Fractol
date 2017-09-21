#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_ITE 50
# define IMG_X 1000
# define IMG_Y 800

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct 		s_data
{
	void			*mlx;
	void			*mlx_window;
	void			*mlx_image;
	char 			*image_string;
	int				s_l;
	int				bpp;
	int				endian;
}					t_data;

typedef struct 		s_base
{
	int				x;
	int				y;
	int				max_ite;
	double			y1;
	double			y2;
	double			x1;
	double			x2;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			tmp;
	double			zoom;
}					t_base;

typedef struct 		s_fract
{
	char			*type;
	t_data			*data;
	t_base			*co;
	int				old_x;
	int				old_y;
}					t_fract;

void				ft_bad_arg(void);
t_data				*ft_create(void);
void				mandelbrot(t_fract *fractal);
void				ft_base_fractale(t_fract *fractal);	
void				ft_error(void);
void				zoom_out(t_fract *fractal);
void				zoom_in(t_fract *fractal);
void				ft_zoom_out(int x, int y, t_fract *fractal);
void				ft_zoom_in(int x, int y, t_fract *fractal);
unsigned int		get_color(int a, t_fract *fractal);
void				put_pxl(t_data *data, int x, int y, unsigned int c);
void				julia(t_fract *fractal);
void				burning(t_fract *fractal);
void				ft_modif_param(int x, int y, t_fract *fractal);

void				ft_key_move(int key, t_fract *fractal);
int					my_key_func(int key, t_fract *fractal);
int					my_expose_hook(t_fract *fractal);
int					my_mouse_hook(int key, int x, int y, t_fract *fractal);
int					mouse_move(int x, int y, t_fract *fractal);
void				ft_exe(t_fract *fractal);

#endif