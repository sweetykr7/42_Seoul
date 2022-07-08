/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_optimizing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:09:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 12:05:52 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_buf	*algorithm_optimize(t_buf *buf)
{
	char	*str1;
	char	*str2;
	char	*str3;
	t_buf	*temp;
	int		flag;

	if (buf->total_cnt < 3)
		return (buf);
	temp = buf;
	flag = 1;
	while (temp->next->next)
	{
		str1 = temp->print_buf;
		str2 = temp->next->print_buf;
		str3 = temp->next->next->print_buf;
		flag = algorithm_optimize_case(temp, str1, str2, str3);
		if (!flag)
			temp = buf;
		else if (temp->next->next && flag)
			temp = temp->next;
		else
			break ;
	}
	return (buf);
}
