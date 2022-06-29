/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:15:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/06/29 13:39:26 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_head *a, t_head *b, int size)
{
	int	para1;
	int	para2;
	int	para3;

	para1 = b->head->data;
	para2 = b->head->next->data;
	if (size == 3)
	{
		para3 = b->head->next->next->data;
		if (para1 < para2 && para2 < para3)
			sort_b_case_1(a, b);
		else if (para1 < para3 && para3 < para2)
			sort_b_case_2(a, b);
		else if (para2 < para1 && para1 < para3)
			sort_b_case_3(a, b);
		else if (para2 < para3 && para3 < para1)
			sort_b_case_4(a, b);
		else if (para3 < para1 && para1 < para2)
			sort_b_case_5(a, b);
		return ;
	}
	sb(b);
	pa(a, b);
	pa(a, b);
}
