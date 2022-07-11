/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:53:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/11 14:17:13 by sooyokim         ###   ########.fr       */
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
	j = -1;
	error = 0;
	while (++i < ac)
	{
		input = split_input(av[i], ' ', &words_cnt);
		if (!input)
			return (0);
		while (++j < words_cnt)
		{
			list_add(a, atoi_input(input[j], &error), 0, &error);
			free(input[j]);
			if (error)
				return (free_char_pointer_and_return_zero(input));
		}
		free(input);
		j = -1;
	}
	return (1);
}
