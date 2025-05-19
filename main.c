/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:41:43 by saderdou          #+#    #+#             */
/*   Updated: 2024/05/23 13:41:49 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}

void	ft_julia(t_data *data, double x, double y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;
	int			color;

	z.real = ((((x - 0) * (2 - -2)) / (800 - 0)) + -2) * data->zoom;
	z.im = ((((y - 0) * (-2 - 2)) / (800 - 0)) + 2) * data->zoom;
	c.real = data->julia_x;
	c.im = data->julia_y;
	i = 0;
	while (i <= 252)
	{
		tmp = z.real;
		z.real = (z.real * z.real) - (z.im * z.im) + c.real;
		z.im = (2 * tmp * z.im) + c.im;
		if ((z.real * z.real) + (z.im * z.im) > 4)
		{
			color = (((i - 0) * (WHITE - BLACK)) / (252 - 0)) + BLACK;
			my_mlx_pixel_put(data, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(data, x, y, WHITE);
}

void	ft_mandelbrot(t_data *data, double x, double y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;
	int			color;

	z.real = 0;
	z.im = 0;
	c.real = ((((x - 0) * (2 - -2)) / (800 - 0)) + -2) * data->zoom;
	c.im = ((((y - 0) * (-2 - 2)) / (800 - 0)) + 2) * data->zoom;
	i = 0;
	while (i <= 252)
	{
		tmp = z.real;
		z.real = (z.real * z.real) - (z.im * z.im) + c.real;
		z.im = (2 * tmp * z.im) + c.im;
		if ((z.real * z.real) + (z.im * z.im) > 4)
		{
			color = (((i - 0) * (WHITE - BLACK)) / (252 - 0)) + BLACK;
			my_mlx_pixel_put(data, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(data, x, y, WHITE);
}

void	fill_up_img(t_data *data)
{
	double	x;
	double	y;

	x = 0;
	while (x < 800)
	{
		y = 0;
		while (y < 800)
		{
			if (ft_strncmp(data->name, "mandelbrot", 11) == 0)
				ft_mandelbrot(data, x, y);
			if (ft_strncmp(data->name, "julia", 6) == 0)
				ft_julia(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 1)
	{
		ft_check_args(ac, av, &data);
		ft_init(&data);
		fill_up_img(&data);
		mlx_key_hook(data.win_ptr, key_hook, &data);
		mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
		mlx_hook(data.win_ptr, 17, 0, destroy, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_error();
	return (0);
}
