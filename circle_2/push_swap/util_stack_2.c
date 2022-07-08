/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:27:31 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 15:44:49 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_reverse_both(t_head *a, t_head *b, t_buf *print_buf)
{
	re_reverse(a, print_buf, 'c');
	re_reverse(b, print_buf, 'c');
}

void	reverse_both(t_head *a, t_head *b, t_buf *print_buf)
{
	reverse(a, print_buf, 'c');
	reverse(b, print_buf, 'c');
}

void	swap_both(t_head *a, t_head *b, t_buf *print_buf)
{
	swap(a, print_buf, 'c');
	swap(b, print_buf, 'c');
}
