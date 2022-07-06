/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 13:34:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_case_1(t_head *a, t_head *b, t_buf *print_buf)
{
	swap(a, print_buf, 'a');
	reverse(a, print_buf, 'a');
	reverse(a, print_buf, 'a');
	push_from_to(a, b, print_buf, 'b');
	re_reverse(a, print_buf, 'a');
	re_reverse(a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
}

void	sort_a_case_2(t_head *a, t_head *b, t_buf *print_buf)
{
	reverse(a, print_buf, 'a');
	reverse(a, print_buf, 'a');
	push_from_to(a, b, print_buf, 'b');
	re_reverse(a, print_buf, 'a');
	re_reverse(a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
}

void	sort_a_case_3(t_head *a, t_buf *print_buf)
{
	swap(a, print_buf, 'a');
	reverse(a, print_buf, 'a');
	swap(a, print_buf, 'a');
	re_reverse(a, print_buf, 'a');
}

void	sort_a_case_4(t_head *a, t_buf *print_buf)
{
	reverse(a, print_buf, 'a');
	swap(a, print_buf, 'a');
	re_reverse(a, print_buf, 'a');
}

void	sort_a_case_5(t_head *a, t_buf *print_buf)
{
	swap(a, print_buf, 'a');
}
