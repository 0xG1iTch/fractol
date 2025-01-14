/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 00:50:17 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-14 00:50:17 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen_to_complex(int x, int y, t_data *data)
{
	t_complex	point;

	point.real = data->center.real + (x - WIDTH / 2) * data->zoom;
	point.imag = data->center.imag + (y - HEIGHT / 2) * data->zoom;
	return (point);
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	int	pixel_index;

	pixel_index = (y * data->line_len) + (x * (data->bpp / 8));
	*(int *)(data->addr + pixel_index) = color;
}

int	get_color(int iter, int max_iter)
{
	int	color_value;
	int	r;
	int	g;
	int	b;

	if (iter == max_iter)
		return (0x000000);
	color_value = (iter * 255 / max_iter);
	r = (int)(127.5 * (sin(color_value * 0.05) + 1));
	g = (int)(127.5 * (sin(color_value * 0.1) + 1));
	b = (int)(127.5 * (sin(color_value * 0.15) + 1));
	return ((r << 16) | (g << 8) | b);
}

void	render_fractal(t_data *data)
{
	int			x;
	int			y;
	int			iter;
	t_complex	point;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			point = screen_to_complex(x, y, data);
			if (data->fractal_type == MANDELBROT)
				iter = mandelbrot(point, data->max_iter);
			else
				iter = julia(point, data->julia_param, data->max_iter);
			put_pixel_to_image(data, x, y, get_color(iter, data->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
