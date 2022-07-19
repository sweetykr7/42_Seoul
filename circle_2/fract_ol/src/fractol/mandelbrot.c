/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:19:58 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 16:26:18 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_count count, int iter, t_viewpoint *vp)
{
	t_complex	c;
	double		x;
	double		x_new;
	double		y;

	c = screen_to_complex(count.i, count.j, vp);
	x = 0;
	y = 0;
	while ((x * x + y * y < 4) && (iter < ITER_MAX))
	{
		x_new = x * x - y * y + c.re;
		y = 2 * x * y + c.im;
		x = x_new;
		iter++;
	}
	return (iter);
}

void	mandelbrot_viewpoint(t_viewpoint *vp)
{
	vp->offx = 0.0f;
	vp->offy = 0.0f;
	vp->xmax = 1.0f;
	vp->xmin = -2.5f;
	vp->ymax = 1.0f;
	vp->ymin = -1.0f;
	vp->zoom = 1.0f;
}
