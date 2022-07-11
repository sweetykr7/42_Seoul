/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_optimize_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:16:08 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 18:32:44 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_optimize_3(t_head *a, t_buf *print_buf)
{
	int	para1;
	int	para2;
	int	para3;
	int	error;

	error = 0;
	para1 = a->head->data;
	para2 = a->head->next->data;
	para3 = a->head->next->next->data;
	write_sort_complete_a(a, a->head->cluster_cnt);
	if (para1 < para3 && para3 < para2)
		sort_a_optimize_case1(a, print_buf, &error);
	else if (para2 < para1 && para1 < para3)
		sort_a_optimize_case2(a, print_buf, &error);
	else if (para3 < para1 && para1 < para2)
		sort_a_optimize_case3(a, print_buf, &error);
	else if (para2 < para3 && para3 < para1)
		sort_a_optimize_case4(a, print_buf, &error);
	else if (para3 < para2 && para2 < para1)
		sort_a_optimize_case5(a, print_buf, &error);
	if (error == 1)
		return (0);
	return (1);
}
