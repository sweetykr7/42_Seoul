/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:05:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/09 13:28:29 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_buf_free(t_buf *buf)
{
	t_buf	*temp;

	while (buf)
	{
		if (buf->next)
			temp = buf->next;
		else
			temp = 0;
		buf = 0;
		free (buf);
		buf = temp;
	}
	free(buf);
}

void	print_buf_out(t_buf *buf)
{
	t_buf	*temp;

	temp = buf;
	while (temp && temp->print_buf)
	{
		print_all(temp->print_buf);
		if (temp->next)
			temp = temp->next;
		else
			break ;
	}
}

void	insert_print_buf_back_area(t_buf *temp, char *res)
{
	t_buf	*res_buf;

	if (!temp->print_buf)
		temp->print_buf = res;
	else
	{
		res_buf = initial_print_buf();
		temp->next = res_buf;
		temp->next->print_buf = res;
		temp->next->next = 0;
	}
}

t_buf	*insert_print_buf(t_buf *buf, char *str)
{
	char	*res;
	t_buf	*temp;
	int		strlen;
	int		i;

	strlen = strsize(str);
	temp = last_buf(buf);
	res = (char *)malloc(sizeof(strlen) + 1);
	if (!res)
	{
		temp->next = 0;
		return (buf);
	}
	i = -1;
	while (++i < strlen)
		res[i] = str[i];
	res[i] = '\0';
	insert_print_buf_back_area(temp, res);
	buf->total_cnt = buf->total_cnt + 1;
	return (buf);
}

t_buf	*initial_print_buf(void)
{
	t_buf	*buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	if (!buf)
		return (0);
	buf->print_buf = 0;
	buf->next = 0;
	buf->total_cnt = 0;
	return (buf);
}
