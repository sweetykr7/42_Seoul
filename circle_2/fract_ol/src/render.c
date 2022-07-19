/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:55:50 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 19:06:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = (img->data) + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

int	color_set(int iter, double color_set)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(color_set * (double)iter);
	g = sin(color_set * (double)iter + 3) * 127 + 128;
	b = sin(color_set * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) \
										+ ((int)(255.999 * b));
	return (color);
}

int	fractol_select(t_count c, int iter, t_mlx *mlx)
{
	if (ft_strcmp(mlx->fractol, "mandelbrot"))
		iter = mandelbrot(c, 0, mlx->vp);
	if (ft_strcmp(mlx->fractol, "julia"))
		iter = julia(c, 0, mlx->vp, mlx->julia_c);
	if (ft_strcmp(mlx->fractol, "burningship"))
		iter = burningship(c, 0, mlx->vp);
	return (iter);
}

void	render(t_mlx *mlx)
{
	t_img	img;
	int		iter;
	int		color;
	t_count	c;

	img = mlx->img;
	c.i = -1;
	while (++c.i < W_WIDTH)
	{
		c.j = -1;
		while (++c.j < W_HEIGHT)
		{
			iter = fractol_select(c, 0, mlx);
			if (iter < ITER_MAX)
			{
				color = color_set(iter, mlx->color_set);
				my_mlx_pixel_put(&img, c.i, c.j, color);
			}
			else
				my_mlx_pixel_put(&img, c.i, c.j, 0x00000000);
		}		
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
								(mlx->img.img_ptr), 0, 0);
}
