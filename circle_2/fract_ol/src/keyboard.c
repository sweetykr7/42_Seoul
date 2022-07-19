/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 05:33:43 by pbondoer          #+#    #+#             */
/*   Updated: 2022/07/19 16:03:39 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>
#include "mlx.h"

int	hook_key(int key, t_mlx *mlx)
{
	if (key == K_ESC)
		terminate_fractol(mlx);
	if (key == K_NUM_0)
		reset_viewpoint(mlx);
	if (key == K_NUM_PLUS)
		zoom(W_WIDTH / 2, W_HEIGHT / 2, mlx, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(W_WIDTH / 2, W_HEIGHT / 2, mlx, ZOOM);
	if (key == K_UP)
		move(0, 0, mlx, 'u');
	if (key == K_DOWN)
		move(0, 0, mlx, 'd');
	if (key == K_LEFT)
		move(0, 0, mlx, 'l');
	if (key == K_RIGHT)
		move(0, 0, mlx, 'r');
	return (0);
}
