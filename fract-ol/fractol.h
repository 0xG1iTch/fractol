/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-12 20:07:22 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-12 20:07:22 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# define WIDTH 1000
# define HEIGHT 1000
# define MANDELBROT 1
# define JULIA 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ESC 53
# define ARROW_UP    126
# define ARROW_DOWN  125
# define ARROW_LEFT  123
# define ARROW_RIGHT 124
# define ZOOM_IN     69    // '+' key
# define ZOOM_OUT    78    // '-' key
# define RESET_KEY   15    // 'R' key
# define INCREASE_ITER 24  // '+' key
# define DECREASE_ITER 27  // '-' key

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			fractal_type;
	int			max_iter;
	double		zoom;
	t_complex	julia_param;
	t_complex	center;
}	t_data;

t_complex	screen_to_complex(int x, int y, t_data *data);
int			parse_arguments(int argc, char **argv, t_data *data);
int			init_mlx(t_data *data);
int			mandelbrot(t_complex c, int max_iter);
int			julia(t_complex z, t_complex c, int max_iter);
int			get_color(int iter, int max_iter);
int			mouse_zoom(int button, int x, int y, t_data *data);
int			key_events(int keycode, t_data *data);
int			close_window(t_data *data);
void		render_fractal(t_data *data);
void		setup_hooks(t_data *data);
void		put_pixel_to_image(t_data *data, int x, int y, int color);

#endif