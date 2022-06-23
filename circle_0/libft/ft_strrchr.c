/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:35:40 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/16 18:51:07 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	char			*result;

	uc = (unsigned char)c;
	result = NULL;
	if (uc == 0)
		result = (char *)(&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == uc)
			result = (char *)s;
		s++;
	}
	return (result);
}
