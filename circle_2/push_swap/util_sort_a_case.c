/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_a_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/29 13:38:55 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_case_1(t_head *a, t_head *b)
{
	sa(a);
	ra(a);
	ra(a);
	pb(a, b);
	rra(a);
	rra(a);
	pa(a, b);
}

void	sort_a_case_2(t_head *a, t_head *b)
{
	ra(a);
	ra(a);
	pb(a, b);
	rra(a);
	rra(a);
	pa(a, b);
}

void	sort_a_case_3(t_head *a, t_head *b)
{
	sa(a);
	ra(a);
	sa(a);
	rra(a);
}

void	sort_a_case_4(t_head *a, t_head *b)
{
	ra(a);
	sa(a);
	rra(a);
}

void	sort_a_case_5(t_head *a, t_head *b)
{
	sa(a);
}

