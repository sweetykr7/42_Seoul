/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:59:50 by sooyokim          #+#    #+#             */
/*   Updated: 2022/03/17 13:37:09 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	find_start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_in(s1[i], set) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	find_end_index(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (is_in(s1[i], set) == 0)
		{
			return (i);
		}
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_i;
	int		end_i;
	int		i;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start_i = find_start_index(s1, set);
	end_i = find_end_index(s1, set);
	if (start_i == -1 && end_i == -1)
	{
		res = (char *)malloc(sizeof(char) * 1);
		if (!res)
			return (NULL);
		res[0] = 0;
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (end_i - start_i + 2));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < end_i - start_i + 1)
		res[i] = s1[start_i + i];
	res[i] = '\0';
	return (res);
}
