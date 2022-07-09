/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:53:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/09 10:53:34 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
