/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 00:50:49 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-14 00:50:49 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_scale;

	mouse_x = data->center.real + (x - WIDTH / 2) * data->zoom;
	mouse_y = data->center.imag + (y - HEIGHT / 2) * data->zoom;
	if (button == 4)
		zoom_scale = 0.9;
	else if (button == 5)
		zoom_scale = 1.1;
	else
		return (0);
	data->zoom *= zoom_scale;
	data->center.real = mouse_x + (data->center.real - mouse_x) * zoom_scale;
	data->center.imag = mouse_y + (data->center.imag - mouse_y) * zoom_scale;
	render_fractal(data);
	return (0);
}

int	key_events(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == ARROW_UP)
		data->center.imag -= 20 * data->zoom;
	else if (keycode == ARROW_DOWN)
		data->center.imag += 20 * data->zoom;
	else if (keycode == ARROW_LEFT)
		data->center.real -= 20 * data->zoom;
	else if (keycode == ARROW_RIGHT)
		data->center.real += 20 * data->zoom;
	else if (keycode == ZOOM_IN)
		data->zoom *= 0.9;
	else if (keycode == ZOOM_OUT)
		data->zoom *= 1.1;
	render_fractal(data);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 4, 0, mouse_zoom, data);
	mlx_key_hook(data->win, key_events, data);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
