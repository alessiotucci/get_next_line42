/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:12 by atucci            #+#    #+#             */
/*   Updated: 2023/02/06 17:27:27 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*pointer;
	static char	*final;
	int			bytes_read;
	int			count;
	int			len;
	
	pointer = malloc(BUFFER_SIZE + 1);
	if (pointer == NULL)
		return (0);
	
	bytes_read = read(fd, pointer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (0);
	if (bytes_read == 0)
		free(pointer);
		return (NULL);

	len = bytes_read;
	count = 0;
	
	final = malloc(sizeof(char) * (len + 1));
	if (final == NULL)
		return (0);

	while (pointer[count] != '\n' && bytes_read > 0)
	{
		final[count] = pointer[count];
		count++;
		if (count == len)
		{
		
			char *temp = realloc(pointer, sizeof(char) * (len + BUFFER_SIZE + 1));
			if (temp == NULL)
				return (0);
			pointer = temp;
			len += BUFFER_SIZE;

			bytes_read = read(fd, pointer + len, BUFFER_SIZE);
			if (bytes_read == -1)
				return (0);
			if (bytes_read == 0)
			{
				free(pointer);
				final[count] = '\0';
				return (final);
			}
		}
	}
	//final[count] = '\n';
	final[count] = '\0';
	free(pointer);
	return (final);
}

int	main()
{
	int	fd;

	fd = open("shortsubject.txt", O_RDONLY);
	printf( "THIS IS THE  LINE: \n%s", get_next_line(fd));
	printf( "THIS IS THE  LINE: \n%s", get_next_line(fd));
	close(fd);
	return (0);
}

