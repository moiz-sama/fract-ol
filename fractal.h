/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:43:56 by saderdou          #+#    #+#             */
/*   Updated: 2024/05/23 13:44:01 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

//COLORS
# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF

//struct
typedef struct s_data
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	double	zoom;

	double	julia_x;
	double	julia_y;

	void	*img; //img_ptr
	char	*addr;
	int		bpp; //bits_per_pixel;
	int		ll; //line_length
	int		e; //endian
}	t_data;

typedef struct complex
{
	double	real;
	double	im;
}	t_complex;

//ft
void	ft_error(void);
void	ft_init(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_check_args(int ac, char **av, t_data *data);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);
void	fill_up_img(t_data *data);

#endif
