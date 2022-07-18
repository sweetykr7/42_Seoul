/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:02:34 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/18 17:12:18 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	move(int x, int y, t_mlx *mlx, char option)
{
	// double		w;
	// double		h;
	// double		nw;
	// double		nh;
	double		moving_unit;
	t_viewpoint	*v;

	v = mlx->vp;
	moving_unit = v->zoom * MOVE;
	// w = (v->xmax - v->xmin) * (v->zoom);
	// h = (v->ymax - v->ymin) * (v->zoom);
	// nw = (v->xmax - v->xmin) * (v->zoom * z);
	// nh = (v->ymax - v->ymin) * (v->zoom * z);
	// v->zoom *= z;
	
	if (option == 'u')
		v->offy -= ((double)1 / W_HEIGHT) * moving_unit;		
	if (option == 'd')
		v->offy += ((double)1 / W_HEIGHT) * moving_unit;
	if (option == 'l')
		v->offx -= ((double)1 / W_WIDTH) * moving_unit;
	if (option == 'r')
		v->offx += ((double)1 / W_WIDTH) * moving_unit;
	//v->offy -= ((double)y / W_HEIGHT) * moving_unit;
	render(mlx);
}
