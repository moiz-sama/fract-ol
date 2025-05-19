/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:17:25 by saderdou          #+#    #+#             */
/*   Updated: 2024/05/23 18:17:28 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_error(void)
{
	write(1, "./fractol mandelbrot \n", 22);
	write(1, "./fractol julia <nb> <nb> \n", 27);
	exit (1);
}

void	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 800, 800, data->name);
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx_ptr, 800, 800);
	if (!data->img)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->e);
	data->zoom = 1;
	return ;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*offset;

	offset = data->addr + (y * data->ll) + (x * (data->bpp / 8));
	*(int *) offset = color;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		(data->zoom) *= 0.8;
		fill_up_img(data);
	}
	if (keycode == 5)
	{
		(data->zoom) *= 1.2;
		fill_up_img(data);
	}
	return (0);
}
