/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:02:34 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/19 16:10:11 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int x, int y, t_mlx *mlx, char option)
{
	double		moving_unit;
	t_viewpoint	*v;

	v = mlx->vp;
	moving_unit = v->zoom * MOVE;
	if (option == 'u')
		v->offy -= ((double)1 / W_HEIGHT) * moving_unit;
	if (option == 'd')
		v->offy += ((double)1 / W_HEIGHT) * moving_unit;
	if (option == 'l')
		v->offx -= ((double)1 / W_WIDTH) * moving_unit;
	if (option == 'r')
		v->offx += ((double)1 / W_WIDTH) * moving_unit;
	render(mlx);
}
