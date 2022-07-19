/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:52:53 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 18:47:09 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	number_check(const char *str)
{
	int	error;

	error = 0;
	atod_check((char *)str, &error);
	if (error)
		return (0);
	return (1);
}

int	julia_check(int ac, const char **av)
{
	if (ac != 4)
	{
		ft_putstr("julia inputs 2 parameter : [julia] [x] [y]\n");
		return (0);
	}
	if (!number_check(av[2]) || !number_check(av[3]))
	{
		ft_putstr("julia parameter have to be only double range number\n");
		return (0);
	}
	return (1);
}

int	input_check(int ac, const char **av)
{
	if (ac < 2)
	{
		ft_putstr("input : [mandelbrot] / [julia] [x] [y] / [burningship]\n");
		return (0);
	}
	if (ft_strcmp("julia", av[1]))
		if (!julia_check(ac, av))
			return (0);
	if (!ft_strcmp("mandelbrot", av[1]) && !ft_strcmp("julia", av[1]) \
									&& !ft_strcmp("burningship", av[1]))
	{
		ft_putstr("input : [mandelbrot] / [julia] [x] [y] / [burningship]\n");
		return (0);
	}
	if (!ft_strcmp("julia", av[1]) && ac != 2)
	{
		ft_putstr("input : [mandelbrot] / [julia] [x] [y] / [burningship]\n");
		return (0);
	}
	return (1);
}
