/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:51:08 by mkoster           #+#    #+#             */
/*   Updated: 2024/04/25 14:02:52 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# define ERROR_MESSAGE	"An error occurred, try:\n\t ./fractol mandelbrot\n\t \
./fractol julia <value1> <value2>\n\t \
./fractol burning_ship\n\t ./fractol cubic\n\t ./fractol nova\n\
Commands:\n\t + := more iterations\n\t - := less iterations\n\t \
mouse_up := zoom_in\n\t mouse_down := zoom_out\n\t \
arrow_keys := move\n\t c := change_color\n"
# define WIDTH 800
# define HEIGHT 800
# define WHITE 0xFFFFFFFF
# define BLACK 0x00000000 

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int     id;
	int		color;
	int		color_l;
	int		color_r;
}	t_fractal;

int			key_handling(int keycode, t_fractal *fractal);
int			close_handling(t_fractal *fractal);
int			mouse_handling(int button, int x, int y, t_fractal *fractal);
int			check_arg(char *s);

void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		ft_init_mandelbrot(t_fractal *fractal);
void		mandelbrot(t_fractal *fractal, int i, int j);
void		render_mandelbrot(t_fractal *fractal);
void		init_fractal(t_fractal *fractal, char **argv, int argc);
void		init_complex_c(t_fractal *fractal, t_complex *c, int y, int i);
void		init_complex_z(t_fractal *fractal, t_complex *z, int y, int i);
void		ft_close(t_fractal *fractal);
void		check_error_julia(char **argv);
void		color_calc(t_fractal *fractal, int x);

double		calc_hypotenuse(t_complex a);
double		scale_func(double num, double new_mi, double new_mx, double old_mx);
double		str_to_double(char *s);

t_complex	complex_sum(t_complex a, t_complex b);
t_complex	complex_sqr(t_complex a);
t_complex	calc_z(t_fractal *fractal, t_complex z, t_complex c);
t_complex	complex_sqr_abs(t_complex z);
t_complex	zoom_calc(t_fractal *fractal, int x, int y);
t_complex	complex_div(t_complex z1, t_complex z2);
t_complex	complex_cubic(t_complex a);
t_complex	complex_mult(t_complex a, double b);
t_complex	complex_minus(t_complex a);
#endif
