/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_optimizing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:09:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/07 19:41:22 by sooyokim         ###   ########.fr       */
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

int	check_words(char *a, char *b)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	if (b[i])
		return (0);
	return (res);
}

int	count_jump_words(t_buf *buf, char *jump_words)
{
	int		cnt;
	t_buf	*temp;

	cnt = 0;
	temp = buf->next;
	while (temp && check_words(temp->print_buf, jump_words))
	{
		cnt++;
		if (temp->next)
			temp = temp->next;
		else
			temp = 0;
	}
	return (cnt);
}

int	jump_check_lastwords(t_buf *buf, char *jump_words, char *words)
{
	t_buf	*temp;

	temp = buf->next;
	while (temp && check_words(temp->print_buf, jump_words))
	{		
		if (temp->next)
			temp = temp->next;
		else
			temp = 0;
	}
	if (!temp)
		return (0);
	return (check_words(temp->print_buf, words));
}

void	del_cnt_change1(t_buf *buf, char *change_words, int cnt, int *flag)
{
	t_buf	*temp;
	t_buf	*temp2;
	t_buf	*last_point;
	t_buf	*del;
	int		i;

	temp = buf;
	i = 0;
	while (i < cnt)
	{
		if (temp->next->next->next)
			last_point = temp->next->next->next;
		else
		{
			last_point = 0;
			break ;
		}
		del = temp->next->next;
		temp = temp->next;
		i++;
	}	
	del->next = 0;
	i = 0;
	temp2 = buf;
	while (i < cnt)
	{
		temp2 = temp2->next;
		i++;
	}		
	temp2->next = last_point;
	free(buf->print_buf);
	buf->print_buf = insert_words(change_words);
	free(del->print_buf);
	free(del);
	*flag = 0;
}	

void	del_3_change_1(t_buf *buf, char *change_words, char *str3, int *flag)
{
	t_buf	*temp;
	t_buf	*del;

	if (buf->next->next->next)
		temp = buf->next->next->next;
	else
		temp = 0;
	del = buf->next->next;
	del->next = 0;
	buf->next->next = temp;
	free(buf->print_buf);
	buf->print_buf = insert_words(change_words);
	free(del->print_buf);
	free(del);
	if (buf->next->next)
		str3 = buf->next->next->print_buf;
	*flag = 0;
}


void	del_2_change_1(t_buf *buf, char *change_words, char *str2, int *flag)
{
	t_buf	*temp;
	t_buf	*del;

	if (buf->next->next)
		temp = buf->next->next;
	else
		temp = 0;
	del = buf->next;
	del->next = 0;
	buf->next = temp;
	free(buf->print_buf);
	buf->print_buf = insert_words(change_words);
	free(del->print_buf);
	free(del);
	str2 = buf->next->print_buf;
	*flag = 0;
}

void	del_2_3(t_buf *buf, char *str2, char *str3, int *flag)
{
	t_buf	*temp;
	t_buf	*del1;
	t_buf	*del2;

	if (buf->next->next->next)
		temp = buf->next->next->next;
	else
		temp = 0;
	del1 = buf->next;
	del2 = buf->next->next;
	del1->next = 0;
	del2->next = 0;
	buf->next = temp;
	free(del1->print_buf);
	free(del2->print_buf);
	free(del1);
	free(del2);
	if (buf->next)
		str2 = buf->next->print_buf;
	else
		str2 = 0;
	if (buf->next->next)
		str3 = buf->next->next->print_buf;
	else
		str3 = 0;
	*flag = 0;
}

int	algorithm_optimize_case(t_buf *buf, char *str1, char *str2, char *str3)
{
	int	flag;

	flag = 1;
	
	if (check_words(str2, "ra\n"))
	{
		if (check_words(str3, "rra\n"))
			del_2_3(buf, str2, str3, &flag);
	}
	else if (check_words(str2, "rra\n"))
	{
		if (check_words(str3, "ra\n"))
			del_2_3(buf, str2, str3, &flag);
	}
	else if (check_words(str2, "rb\n"))
	{
		if (check_words(str3, "rrb\n"))
			del_2_3(buf, str2, str3, &flag);
	}
	else if (check_words(str2, "rrb\n"))
	{
		if (check_words(str3, "rb\n"))
			del_2_3(buf, str2, str3, &flag);
	}
	if (!flag)
		return (0);	
	//(void)str1;
	if (check_words(str1, "ra\n"))
	{
		if (check_words(str2, "rb\n"))
			del_2_change_1(buf, "rr\n", str2, &flag);
		else if (check_words(str2, "rr\n") && jump_check_lastwords(buf, "rr\n", "rb\n"))
			del_cnt_change1(buf, "rr\n", count_jump_words(buf, "rr\n"), &flag);	
	}
	else if (check_words(str1, "rb\n"))
	{
		if (check_words(str2, "ra\n"))
			del_2_change_1(buf, "rr\n", str2, &flag);
		else if (check_words(str2, "rr\n") && jump_check_lastwords(buf, "rr\n", "ra\n"))
			del_cnt_change1(buf, "rr\n", count_jump_words(buf, "rr\n"), &flag);	
	}
	else if (check_words(str1, "rra\n"))
	{
		if (check_words(str2, "rrb\n"))
			del_2_change_1(buf, "rrr\n", str2, &flag);	
		else if (check_words(str2, "rrr\n") && jump_check_lastwords(buf, "rrr\n", "rrb\n"))
			del_cnt_change1(buf, "rrr\n", count_jump_words(buf, "rrr\n"), &flag);
		
	}
	else if (check_words(str1, "rrb\n"))
	{
		if (check_words(str2, "rra\n"))
			del_2_change_1(buf, "rrr\n", str2, &flag);
		else if (check_words(str2, "rrr\n") && jump_check_lastwords(buf, "rrr\n", "rra\n"))
			del_cnt_change1(buf, "rrr\n", count_jump_words(buf, "rrr\n"), &flag);
	}


	if (!flag)
		return (0);
	if (check_words(str1, "sa\n"))
	{
		if (check_words(str2, "sb\n"))
			del_2_change_1(buf, "ss\n", str2, &flag);	
		else if (check_words(str2, "ss\n") && jump_check_lastwords(buf, "ss\n", "sb\n"))
			del_cnt_change1(buf, "ss\n", count_jump_words(buf, "ss\n"), &flag);
	}
	else if (check_words(str1, "sb\n"))
	{
		if (check_words(str2, "sa\n"))
			del_2_change_1(buf, "ss\n", str2, &flag);	
		else if (check_words(str2, "ss\n") && jump_check_lastwords(buf, "ss\n", "sa\n"))
			del_cnt_change1(buf, "ss\n", count_jump_words(buf, "ss\n"), &flag);
	}

	return (flag);
}

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
