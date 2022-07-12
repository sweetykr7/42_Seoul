/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:13 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/12 10:39:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*rv;

	if (!s2)
		return (0);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	rv = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!rv)
	{
		free(s1);
		return (0);
	}
	if (s1)
		while (s1[++i])
			rv[i] = s1[i];
	while (s2[j])
		rv[i++] = s2[j++];
	rv[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (rv);
}

int	ft_is_in(char *str, char c)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
