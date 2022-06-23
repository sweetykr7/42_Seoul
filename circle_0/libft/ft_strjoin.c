/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:31:51 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/15 17:46:22 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*rv;

	if (!s1 || !s2)
		return (NULL);
	rv = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rv)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		rv[i] = s1[i];
		i++;
	}	
	j = 0;
	while (j < ft_strlen(s2))
	{
		rv[i + j] = s2[j];
		j++;
	}
	rv[i + j] = '\0';
	return (rv);
}
