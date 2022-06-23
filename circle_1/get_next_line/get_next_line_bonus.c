/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:02:17 by sooyokim          #+#    #+#             */
/*   Updated: 2022/04/11 17:43:45 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *backup, size_t i)
{
	char	*next_line;

	if (!backup[i])
		return (0);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!next_line)
		return (0);
	i = 0;
	while (backup[i])
	{
		next_line[i] = backup[i];
		if (backup[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_backup_convert(char *backup)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (0);
	}
	if (backup[i] == '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!res)
		return (0);
	while (backup[i])
		res[j++] = backup[i++];
	res[j] = '\0';
	free(backup);
	return (res);
}

char	*ft_read_data(int fd, char *backup)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	read_bytes = 1;
	while (!ft_is_in(backup, '\n') && read_bytes != 0)
	{	
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (0);
		}
		buf[read_bytes] = '\0';
		backup = ft_strjoin(backup, buf, -1, 0);
		if (!backup)
			break ;
	}
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	backup[fd] = ft_read_data(fd, backup[fd]);
	if (!backup[fd])
		return (0);
	next_line = ft_get_line(backup[fd], 0);
	backup[fd] = ft_backup_convert(backup[fd]);
	return (next_line);
}
