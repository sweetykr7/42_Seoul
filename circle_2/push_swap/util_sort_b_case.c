/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_b_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/29 13:39:10 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_case_1(t_head *a, t_head *b)
{
	rb(b);
	sb(b);
	pa(a, b);
	pa(a, b);
	rrb(b);
	pa(a, b);
}

void	sort_b_case_2(t_head *a, t_head *b)
{
	rb(b);
	pa(a, b);
	pa(a, b);
	rrb(b);
	pa(a, b);
}

void	sort_b_case_3(t_head *a, t_head *b)
{
	rrb(b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_b_case_4(t_head *a, t_head *b)
{
	sb(b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_b_case_5(t_head *a, t_head *b)
{
	pa(a, b);
	sb(b);
	pa(a, b);
	pa(a, b);
}
