/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:52:53 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/14 19:17:20 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W_WIDTH 800
# define W_HEIGHT 600
# define ITER_MAX 50

typedef struct structure_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct structure_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
}				t_mlx;

#endif