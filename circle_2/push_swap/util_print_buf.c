/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:05:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 17:32:27 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_print_buf(t_buf *buf, char *str)
{
	int		i;
	int		j;
	char	*rv;
	char	*temp;

	if (!buf->print_buf || !str)
		return ;
	temp = buf->print_buf;
	rv = (char *)malloc(sizeof(char) * (strsize(buf->print_buf) \
			+ strsize(str) + 2));
	if (!rv)
		return ;
	i = -1;
	while (++i < strsize(buf->print_buf))
		rv[i] = buf->print_buf[i];
	j = -1;
	while (++j < strsize(str))
		rv[i + j] = str[j];
	rv[i + j] = '\n';
	rv[i + j + 1] = '\0';
	buf->print_buf = rv;
	buf->print_cnt = buf->print_cnt + 1;
	free(temp);
}

t_buf	*initial_print_buf(void)
{
	t_buf	*buf;
	char	*print_buf;

	buf = (t_buf *)malloc(sizeof(t_buf));
	if (!buf)
		return (0);
	print_buf = (char *)malloc(sizeof(char) * 1);
	if (!print_buf)
		return (0);
	print_buf[0] = '\0';
	buf->print_cnt = 0;
	buf->print_buf = print_buf;
	return (buf);
}
