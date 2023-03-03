/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:26:26 by atucci            #+#    #+#             */
/*   Updated: 2023/03/03 14:40:45 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_to_backup(int fd, char *backup)
{
	char	*buff;
	int		bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(backup, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[4096]; // #bonus: use an array of backup for multiple fds

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	backup[fd] = ft_read_to_backup(fd, backup[fd]); // read from file descriptor and update backup
	if (!backup[fd])
		return (NULL); // return null if there's no backup

	line = ft_get_line(backup[fd]); // extract line from backup
	backup[fd] = ft_backup(backup[fd]); // backup remaining string for future calls

	return (line); // return the line read
}

