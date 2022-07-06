/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:05:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/06 17:20:18 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	insert_print_buf(t_buf *buf, char *str)
// {
// 	(void)buf;
// 	(void)str;
// 	// int		i;
// 	// int		j;
// 	// char	*rv;
// 	// char	*temp;

// 	// if (!buf->print_buf || !str)
// 	// 	return ;
// 	// temp = buf->print_buf;
// 	// rv = (char *)malloc(sizeof(char) * (strsize(buf->print_buf) \
// 	// 		+ strsize(str) + 2));
// 	// if (!rv)
// 	// 	return ;
// 	// i = -1;
// 	// while (++i < strsize(buf->print_buf))
// 	// 	rv[i] = buf->print_buf[i];
// 	// j = -1;
// 	// while (++j < strsize(str))
// 	// 	rv[i + j] = str[j];
// 	// rv[i + j] = '\n';
// 	// rv[i + j + 1] = '\0';
// 	// buf->print_buf = rv;
// 	// buf->print_cnt = buf->print_cnt + 1;
// 	// free(temp);
// }

void	free_print_buf(t_buf *buf)
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
			break;
	}
}

t_buf	*last_buf(t_buf *buf)
{
	t_buf	*temp;

	temp = 0;
	while (buf->next)
		buf = buf->next;
	temp = buf;
	return (temp);
}

t_buf	*insert_print_buf(t_buf *buf, char *str)
{
	char	*res;
	t_buf	*temp;
	t_buf	*res_buf;
	int		strlen;
	int		i;

	strlen = strsize(str);
	temp = last_buf(buf);
	res = (char *)malloc(sizeof(strlen) + 1);
	if (!res)
	{
		temp->next = 0;
		temp->print_buf = 0;
		return (buf);
	}
	i = 0;
	while (i < strlen)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	if (!temp->print_buf)
		temp->print_buf = res;
	else
	{
		res_buf = initial_print_buf();
		temp->next = res_buf;
		temp->next->print_buf = res;
		temp->next->next = 0;
	}
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
