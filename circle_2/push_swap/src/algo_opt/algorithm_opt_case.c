/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_opt_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:05:22 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 12:05:45 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_available_r_rr_delete(t_buf *buf, char *str2, char *str3, int *flag)
{
	if (check_words(str2, "ra\n"))
	{
		if (check_words(str3, "rra\n"))
			del_2_3(buf, str2, str3, flag);
	}
	else if (check_words(str2, "rra\n"))
	{
		if (check_words(str3, "ra\n"))
			del_2_3(buf, str2, str3, flag);
	}
	else if (check_words(str2, "rb\n"))
	{
		if (check_words(str3, "rrb\n"))
			del_2_3(buf, str2, str3, flag);
	}
	else if (check_words(str2, "rrb\n"))
	{
		if (check_words(str3, "rb\n"))
			del_2_3(buf, str2, str3, flag);
	}
	return (*flag);
}

int	check_available_change_rrr(t_buf *buf, char *str1, char *str2, int *flag)
{
	if (check_words(str1, "rra\n"))
	{
		if (check_words(str2, "rrb\n"))
			del_2_change_1(buf, "rrr\n", str2, flag);
		else if (check_words(str2, "rrr\n") && jump_check(buf, "rrr\n", "rrb\n"))
			del_cnt_change1(buf, "rrr\n", count_jump_words(buf, "rrr\n"), flag);
	}
	if (check_words(str1, "rrb\n"))
	{
		if (check_words(str2, "rra\n"))
			del_2_change_1(buf, "rrr\n", str2, flag);
		else if (check_words(str2, "rrr\n") && jump_check(buf, "rrr\n", "rra\n"))
			del_cnt_change1(buf, "rrr\n", count_jump_words(buf, "rrr\n"), flag);
	}
	return (*flag);
}

int	check_available_change_rr(t_buf *buf, char *str1, char *str2, int *flag)
{
	if (check_words(str1, "ra\n"))
	{
		if (check_words(str2, "rb\n"))
			del_2_change_1(buf, "rr\n", str2, flag);
		else if (check_words(str2, "rr\n") && jump_check(buf, "rr\n", "rb\n"))
			del_cnt_change1(buf, "rr\n", count_jump_words(buf, "rr\n"), flag);
	}
	else if (check_words(str1, "rb\n"))
	{
		if (check_words(str2, "ra\n"))
			del_2_change_1(buf, "rr\n", str2, flag);
		else if (check_words(str2, "rr\n") && jump_check(buf, "rr\n", "ra\n"))
			del_cnt_change1(buf, "rr\n", count_jump_words(buf, "rr\n"), flag);
	}
	return (*flag);
}

int	check_available_change_ss(t_buf *buf, char *str1, char *str2, int *flag)
{
	if (check_words(str1, "sa\n"))
	{
		if (check_words(str2, "sb\n"))
			del_2_change_1(buf, "ss\n", str2, flag);
		else if (check_words(str2, "ss\n") && jump_check(buf, "ss\n", "sb\n"))
			del_cnt_change1(buf, "ss\n", count_jump_words(buf, "ss\n"), flag);
	}
	else if (check_words(str1, "sb\n"))
	{
		if (check_words(str2, "sa\n"))
			del_2_change_1(buf, "ss\n", str2, flag);
		else if (check_words(str2, "ss\n") && jump_check(buf, "ss\n", "sa\n"))
			del_cnt_change1(buf, "ss\n", count_jump_words(buf, "ss\n"), flag);
	}
	return (*flag);
}

int	algorithm_optimize_case(t_buf *buf, char *str1, char *str2, char *str3)
{
	int	flag;

	flag = 1;
	if (!check_available_r_rr_delete(buf, str2, str3, &flag))
		return (flag);
	if (!check_available_change_rr(buf, str1, str2, &flag))
		return (flag);
	if (!check_available_change_rrr(buf, str1, str2, &flag))
		return (flag);
	check_available_change_ss(buf, str1, str2, &flag);
	return (flag);
}
