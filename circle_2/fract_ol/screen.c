/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:03:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/18 19:07:11 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen_to_complex(int count_x, int count_y, t_viewpoint *vp)
{
	t_complex	c;

	c.re = (count_x * (vp->xmax - vp->xmin) / W_WIDTH) * \
							vp->zoom + vp->xmin + vp->offx;
	c.im = (count_y * (vp->ymax - vp->ymin) / W_WIDTH) * \
							vp->zoom + vp->ymin + vp->offy;
	return (c);
}
