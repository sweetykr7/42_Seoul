/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_check_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:26:23 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/12 11:04:20 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	instruction_check(char *str)
{
	if (check_words(str, "pa\n"))
		return (1);
	if (check_words(str, "pb\n"))
		return (1);
	if (check_words(str, "ra\n"))
		return (1);
	if (check_words(str, "rb\n"))
		return (1);
	if (check_words(str, "rr\n"))
		return (1);
	if (check_words(str, "rra\n"))
		return (1);
	if (check_words(str, "rrb\n"))
		return (1);
	if (check_words(str, "rrr\n"))
		return (1);
	if (check_words(str, "sa\n"))
		return (1);
	if (check_words(str, "sb\n"))
		return (1);
	if (check_words(str, "ss\n"))
		return (1);
	return (0);
}
