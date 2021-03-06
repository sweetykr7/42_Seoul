/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:26:53 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/09 10:59:30 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_buf	*last_buf(t_buf *buf)
{
	t_buf	*temp;

	temp = 0;
	while (buf->next)
		buf = buf->next;
	temp = buf;
	return (temp);
}

int	find_word_in_list(t_list *lst, int data, int *error)
{
	while (lst)
	{
		if (lst->data == data)
		{
			*error = 1;
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	free_char_pointer_and_return_zero(char **a)
{
	free(a);
	return (0);
}

int	all_free_with_error(t_head *a, t_head *b, t_buf *buf)
{
	if (a)
		head_free(a);
	if (b)
		head_free(b);
	if (buf)
		print_buf_free(buf);
	print_all("Error\n");
	return (0);
}

void	all_free(t_head *a, t_head *b, t_buf *buf)
{
	if (a)
		head_free(a);
	if (b)
		head_free(b);
	if (buf)
		print_buf_free(buf);
}
