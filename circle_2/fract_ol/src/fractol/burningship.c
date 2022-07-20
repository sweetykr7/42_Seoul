/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:29:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/20 13:00:06 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	burningship(t_count count, int iter, t_viewpoint *v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;

	z.re = 0;
	z.im = 0;
	c = screen_to_complex(count.i, count.j, v);
	while (z.re * z.re + z.im * z.im < 4 && iter < ITER_MAX)
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
		z.re = temp.re;
		z.im = temp.im;
		iter++;
	}
	return (iter);
}

void	burningship_viewpoint(t_viewpoint *v)
{
	v->xmin = -2.0;
	v->xmax = 1.0;
	v->ymin = -2.0;
	v->ymax = 1.0;
	v->offx = 0.0;
	v->offy = 0.0;
}
