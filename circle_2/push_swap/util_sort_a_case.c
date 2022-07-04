/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 15:20:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_case_1(t_head *a, t_head *b, t_buf *print_buf)
{
	sa(a, print_buf);
	ra(a, print_buf);
	ra(a, print_buf);
	pb(a, b, print_buf);
	rra(a, 0, print_buf);
	rra(a, 0, print_buf);
	pa(a, b, print_buf);
}

void	sort_a_case_2(t_head *a, t_head *b, t_buf *print_buf)
{
	ra(a, print_buf);
	ra(a, print_buf);
	pb(a, b, print_buf);
	rra(a, 0, print_buf);
	rra(a, 0, print_buf);
	pa(a, b, print_buf);
}

void	sort_a_case_3(t_head *a, t_buf *print_buf)
{
	sa(a, print_buf);
	ra(a, print_buf);
	sa(a, print_buf);
	rra(a, 0, print_buf);
}

void	sort_a_case_4(t_head *a, t_buf *print_buf)
{
	ra(a, print_buf);
	sa(a, print_buf);
	rra(a, 0, print_buf);
}

void	sort_a_case_5(t_head *a, t_buf *print_buf)
{
	sa(a, print_buf);
}
