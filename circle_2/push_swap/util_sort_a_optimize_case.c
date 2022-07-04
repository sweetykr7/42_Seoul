/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a_optimize_case.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:56:00 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 21:01:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_optimize_case1(t_head *a, t_buf *print_buf)
{
	rra(a, 0, print_buf);
	sa(a, print_buf);
}

void	sort_a_optimize_case2(t_head *a, t_buf *print_buf)
{
	sa(a, print_buf);
}

void	sort_a_optimize_case3(t_head *a, t_buf *print_buf)
{
	rra(a, 0, print_buf);
}

void	sort_a_optimize_case4(t_head *a, t_buf *print_buf)
{
	ra(a, print_buf);
}

void	sort_a_optimize_case5(t_head *a, t_buf *print_buf)
{
	sa(a, print_buf);
	rra(a, 0, print_buf);
}
