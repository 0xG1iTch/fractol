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

void	print_usage(void)
{
	write(1, "\n\033[1;34mUsage:\n", 15);
	write(1, "\033[1;34m./fractol <fractal_type>\n\n", 33);
	write(1, "\033[1;32mAvailable fractals:\n\n", 28);
	write(1, "\033[1;33m  🌀 mandelbrot\n", 25);
	write(1, "\033[1;35m  🌊 julia <real> <imag>\n", 34);
	write(1, "\033[1;36m  🔥 burning_ship\n\n", 28);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (HEIGHT <= 0 || HEIGHT > 2500 || WIDTH <= 0 || WIDTH > 2500)
		exit(1);
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
