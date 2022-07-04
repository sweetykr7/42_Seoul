/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:18 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 18:22:48 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pc	*pivot_cnt_pre_set(t_pc *pivot_cnt)
{
	pivot_cnt = (t_pc *)malloc(sizeof(pivot_cnt));
	if (!pivot_cnt)
		return (0);
	pivot_cnt->pivot1_cnt = 0;
	pivot_cnt->pivot2_cnt = 0;
	pivot_cnt->pivot3_cnt = 0;
	return (pivot_cnt);
}

void	print_all(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}
