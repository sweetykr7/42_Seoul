/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:08:51 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/15 15:23:11 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_re;
	unsigned char	*s2_re;

	s1_re = (unsigned char *)s1;
	s2_re = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_re[i] != s2_re[i])
			return (s1_re[i] - s2_re[i]);
		i++;
	}
	return (0);
}
