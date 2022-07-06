/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_optimizing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:09:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 17:44:40 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_buf	*last_second_buf(t_buf *buf)
{
	t_buf	*temp;

	temp = 0;
	while (buf->next->next)
		buf = buf->next;
	temp = buf;
	return (temp);
}

t_buf	*algorithm_optimize_case(t_buf *buf, char *last, char *this)
{
	
}

t_buf	*algorithm_optimize(t_buf *buf)
{
	char	*last;
	char	*this;
	t_buf	*temp;

	if (buf->total_cnt < 2)
		return (buf);
	temp = temp->next;
	while (temp)
	{
		last = temp->print_buf;
		if (temp->next)
		{
			temp = temp->next;
			this = temp->print_buf;
		}
		else
			break ;
		algorithm_optimize_case(buf, last, this);
	}
	
	this_print_buf = last_second_buf(buf);
	last = last_print_buf->print_buf;
	this = this_print_buf->print_buf;
	algorithm_optimize_case(buf, last, this);
	return (buf);
}
