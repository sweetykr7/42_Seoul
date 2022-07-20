/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:25:20 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/20 13:00:14 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_count count, int iter, t_viewpoint *vp, t_complex c)
{
	t_complex	z;
	double		x;
	double		x_new;
	double		y;

	z = screen_to_complex(count.i, count.j, vp);
	x = z.re;
	y = z.im;
	while ((x * x + y * y < 4) && (iter < ITER_MAX))
	{
		x_new = x * x - y * y + c.re;
		y = 2 * x * y + c.im;
		x = x_new;
		iter++;
	}
	return (iter);
}

void	julia_viewpoint(t_viewpoint *v)
{
	v->offy = 0.0;
	v->xmin = -2.0;
	v->xmax = 2.0;
	v->ymin = -1.0;
	v->ymax = 1.0;
}
