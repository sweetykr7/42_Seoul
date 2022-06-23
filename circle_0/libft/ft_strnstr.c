/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:35:31 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/18 12:14:19 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *finds, size_t len)
{
	int		i;
	size_t	j;
	char	*r;

	i = 0;
	if (*finds == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		if (str[i] == finds[j])
		{
			r = &((char *)str)[i];
			while (str[i + j] && (str[i + j] == finds[j]) && (i + j) < len)
				j++;
			if (j == ft_strlen(finds))
				return (r);
		}
		i++;
	}
	return (NULL);
}
