/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a_optimize_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:56:00 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 13:40:49 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_optimize_case1(t_head *a, t_buf *print_buf)
{
	re_reverse(a, print_buf, 'a');
	swap(a, print_buf, 'a');
}

void	sort_a_optimize_case2(t_head *a, t_buf *print_buf)
{
	swap(a, print_buf, 'a');
}

void	sort_a_optimize_case3(t_head *a, t_buf *print_buf)
{
	re_reverse(a, print_buf, 'a');
}

void	sort_a_optimize_case4(t_head *a, t_buf *print_buf)
{
	reverse(a, print_buf, 'a');
}

void	sort_a_optimize_case5(t_head *a, t_buf *print_buf)
{
	swap(a, print_buf, 'a');
	re_reverse(a, print_buf, 'a');
}
