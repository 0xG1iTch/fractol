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
	if (button == SCROLL_UP)
		data->zoom *= 0.9;
	if (button == SCROLL_DOWN)
		data->zoom *= 1.1;
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
