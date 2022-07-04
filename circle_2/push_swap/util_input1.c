/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_input1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:23:52 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/04 12:26:18 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_all(char **arr, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*get_word(const char *s, char c, int *len)
{	
	char	*word;
	int		i;

	i = 0;
	while ((s[i] != c) && s[i])
	{
		i++;
		(*len)++;
	}	
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	while (s[i] == c)
	{
		(*len)++;
		i++;
	}
	return (word);
}

int	put_word(char **result, char const *s, char c, int words)
{
	int	i;
	int	len;
	int	ml_cnt;

	i = 0;
	len = 0;
	while (s[i] == c && s[i])
	{
		len++;
		i++;
	}	
	i = 0;
	ml_cnt = 0;
	while (i < words)
	{
		result[i] = get_word((s + len), c, &len);
		ml_cnt++;
		if (!result[i])
		{
			free_all(result, ml_cnt);
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_word(char const *s, char c)
{
	int		count;
	int		i;
	char	sc;
	char	sc_right;

	count = 0;
	i = 0;
	while (s[i])
	{
		sc = s[i];
		sc_right = s[i + 1];
		if ((i == 0 && sc != c) || (sc == c && sc_right && sc_right != c))
			count++;
		i++;
	}
	return (count);
}

char	**split_input(char const *s, char c, int *words_cnt)
{
	char	**result;	
	int		words;
	int		err_chk;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	err_chk = 1;
	err_chk = put_word(result, s, c, words);
	result[words] = 0;
	*words_cnt = words;
	if (err_chk == 1)
		return (result);
	else
		return (NULL);
}
