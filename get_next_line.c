/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:51:04 by atucci            #+#    #+#             */
/*   Updated: 2023/02/20 18:20:30 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*pointer = NULL;
	static int	count = 0;
	int			len;
	int			bytes_read;
	char		*final;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!pointer)
	{
		pointer = malloc(BUFFER_SIZE + 1);
		if (!pointer)
			return (NULL);
		bytes_read = read(fd, pointer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			return (NULL);
		len = ft_strlen(pointer);
	}
	else
		len = ft_strlen(pointer + count);
final = malloc(sizeof(char) * (len + 1));
	if (!final)
	{
		free(pointer);
		return (NULL);
	}
i = 0;
	while (i < len)
	{
		if (pointer[count + i] == '\n')
		{
		final[i] = '\n';
		final[i + 1] = '\0';
		count += i + 1;
			return (final);
		}
	final[i] = pointer[count + i];
	i++;
	}
count += len;
//gpt fix
final[i] = '\0'; // making sure final is alwalys null terminated
	if (!pointer)
	pointer = realloc(pointer, sizeof(char) * (len + BUFFER_SIZE + 1));
	if (!pointer)
	{
		free(final);
		return (NULL);
	}
bytes_read = read(fd, pointer + len, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		if (final && ft_strlen(final) > 0) // my fix
		{
			final[i] = '\0';
			free(pointer);
			pointer = NULL;
			return (final);
		}
		free(pointer);
		free(final);
		return (NULL);
	}
	return (get_next_line(fd));
}
