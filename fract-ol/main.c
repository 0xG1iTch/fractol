/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-12 16:47:39 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-12 16:47:39 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	write(1, "Usage: ./fractol <fractal_type>\n", 32);
	write(1, "Available fractals:\n", 20);
	write(1, "  mandelbrot\n", 13);
	write(1, "  julia <real> <imag>\n", 22);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!parse_arguments(argc, argv, &data))
	{
		print_usage();
		return (1);
	}
	if (!init_mlx(&data))
	{
		write(2, "Error initializing MiniLibX\n", 28);
		return (1);
	}
	render_fractal(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
