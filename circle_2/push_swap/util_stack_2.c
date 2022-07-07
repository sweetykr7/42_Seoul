/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:27:31 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 09:55:21 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_reverse_both(t_head *a, t_head *b, t_buf *print_buf)
{
	re_reverse(a, print_buf, 'r');
	re_reverse(b, print_buf, 'r');
}
