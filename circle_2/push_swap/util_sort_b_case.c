/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_b_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/01 11:00:51 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_case_1(t_head *a, t_head *b, char *print_buf)
{
	rb(b, print_buf);
	sb(b, print_buf);
	pa(a, b, print_buf);
	pa(a, b, print_buf);
	rrb(b, print_buf);
	pa(a, b, print_buf);
}

void	sort_b_case_2(t_head *a, t_head *b, char *print_buf)
{
	rb(b, print_buf);
	pa(a, b, print_buf);
	pa(a, b, print_buf);
	rrb(b, print_buf);
	pa(a, b, print_buf);
}

void	sort_b_case_3(t_head *a, t_head *b, char *print_buf)
{
	rb(b, print_buf);
	rb(b, print_buf);
	pa(a, b, print_buf);
	rrb(b, print_buf);
	rrb(b, print_buf);
	pa(a, b, print_buf);
	pa(a, b, print_buf);
}

void	sort_b_case_4(t_head *a, t_head *b, char *print_buf)
{
	sb(b, print_buf);
	pa(a, b, print_buf);
	pa(a, b, print_buf);
	pa(a, b, print_buf);
}

void	sort_b_case_5(t_head *a, t_head *b, char *print_buf)
{
	pa(a, b, print_buf);
	sb(b, print_buf);
	pa(a, b, print_buf);
	pa(a, b, print_buf);
}
