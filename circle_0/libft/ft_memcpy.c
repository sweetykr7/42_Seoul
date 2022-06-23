/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:20:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/21 20:59:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_re;
	unsigned char	*src_re;

	dst_re = (unsigned char *)(dst);
	src_re = (unsigned char *)(src);
	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_re[i] = src_re[i];
		i++;
	}
	return (dst_re);
}
