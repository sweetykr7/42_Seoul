/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_b_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 13:38:21 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_case_1(t_head *a, t_head *b, t_buf *print_buf)
{
	reverse(b, print_buf, 'b');
	swap(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
	re_reverse(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
}

void	sort_b_case_2(t_head *a, t_head *b, t_buf *print_buf)
{
	reverse(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
	re_reverse(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
}

void	sort_b_case_3(t_head *a, t_head *b, t_buf *print_buf)
{
	reverse(b, print_buf, 'b');
	reverse(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	re_reverse(b, print_buf, 'b');
	re_reverse(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
}

void	sort_b_case_4(t_head *a, t_head *b, t_buf *print_buf)
{
	swap(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
}

void	sort_b_case_5(t_head *a, t_head *b, t_buf *print_buf)
{
	push_from_to(b, a, print_buf, 'a');
	swap(b, print_buf, 'b');
	push_from_to(b, a, print_buf, 'a');
	push_from_to(b, a, print_buf, 'a');
}
