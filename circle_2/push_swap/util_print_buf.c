/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:05:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/01 11:35:32 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	*insert_print_buf(char *print_buf, char *str)
{
	int		i;
	int		j;
	char	*rv;

	if (!print_buf || !str)
		return (NULL);
	rv = (char *)malloc(sizeof(char) * (strsize(print_buf) + strsize(str) + 1));
	if (!rv)
		return (NULL);
	i = 0;
	while (i < strsize(print_buf))
	{
		rv[i] = print_buf[i];
		i++;
	}	
	j = 0;
	while (j < strsize(str))
	{
		rv[i + j] = str[j];
		j++;
	}
	rv[i + j] = '\0';
	return (rv);
}
