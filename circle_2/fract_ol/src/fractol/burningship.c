/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:29:29 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 16:29:43 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	burningship(t_count count, int iter, t_viewpoint *v)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;

	z = screen_to_complex(count.i, count.j, v);
	c = screen_to_complex(count.i, count.j, v);
	while (z.re * z.re + z.im * z.im < 4 && iter < ITER_MAX)
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		temp.re = z.re * z.re - z.im * z.im + c.re;
		temp.im = z.re * z.im * 2 + c.im;
		if (z.re == temp.re && z.im == temp.im)
		{
			iter = ITER_MAX;
			break ;
		}
		z.re = temp.re;
		z.im = temp.im;
		iter++;
	}
	return (iter);
}

void	burningship_viewpoint(t_viewpoint *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = 0.0f;
	v->offy = 0.0f;
}
