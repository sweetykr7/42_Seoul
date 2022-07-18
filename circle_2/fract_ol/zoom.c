/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:54:35 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/18 18:29:42 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_mlx *mlx, double z)
{
	double		w;
	double		h;
	double		nw;
	double		nh;
	t_viewpoint	*v;

	v = mlx->vp;
	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / W_WIDTH) * (nw - w);
	v->offy -= ((double)y / W_HEIGHT) * (nh - h);
	render(mlx);
}
