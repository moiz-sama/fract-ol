/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saderdou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:07:33 by saderdou          #+#    #+#             */
/*   Updated: 2024/05/14 11:07:56 by saderdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_parse(char *str)
{
	int	i;
	int	sign_count;
	int	point_count;
	int	nb;

	i = 0;
	sign_count = 0;
	point_count = 0;
	nb = 0;
	while (str && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		if (str[i] == '-' || str[i] == '+')
			sign_count++;
		if (str[i] == '.')
			point_count++;
		if (str[i] >= '0' && str[i] <= '9')
			nb++;
		i++;
	}
	if (sign_count > 1 || point_count > 1 || nb == 0)
		return (0);
	return (1);
}

double	ft_atod(char *str)
{
	long	r;
	double	r2;
	double	power;
	int		sign;

	r = 0;
	r2 = 0;
	sign = 1;
	power = 1;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			sign = -sign;
	while (*str >= '0' && *str <= '9')
		r = (r * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error();
		power /= 10;
		r2 = r2 + (*str++ - 48) * power;
	}
	return ((r + r2) * sign);
}

void	ft_check_args(int ac, char **av, t_data *data)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		data->name = av[1];
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		if (ft_parse(av[2]) == 1 && ft_parse(av[3]) == 1)
		{
			data->julia_x = ft_atod(av[2]);
			data->julia_y = ft_atod(av[3]);
			data->name = av[1];
		}
		else
			ft_error();
	}
	else
		ft_error();
}
