/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:30:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/08 15:46:56 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	head_free(a);
	head_free(b);
	print_buf_free(buf);
}

int	get_number(char	**av, int ac, t_head *a)
{	
	char	**input;
	int		i;
	int		j;
	int		words_cnt;
	int		error;

	i = 0;
	j = 0;
	error = 0;
	while (++i < ac)
	{
		input = split_input(av[i], ' ', &words_cnt);
		while (j < words_cnt)
		{
			list_add(a, atoi_input(input[j], &error), 0, &error);
			free(input[j]);
			if (error)
				return (free_char_pointer_and_return_zero(input));
			j++;
		}
		free(input);
		j = -1;
		j = 0;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_head	*a;
	t_head	*b;
	t_buf	*buf;

	if (ac < 2)
		return (0);
	a = new_head();
	b = new_head();
	buf = initial_print_buf();
	if (!a || !b || !buf)
		return (all_free_with_error(a, b, buf));
	if (!get_number(av, ac, a))
		return (all_free_with_error(a, b, buf));
	a->head->cluster_cnt = a->total_cnt;
	divide_stack_recur(a, b, a->total_cnt, buf);
	buf = algorithm_optimize(buf);
	print_buf_out(buf);
	all_free(a, b, buf);
	return (0);
}
