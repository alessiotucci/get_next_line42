/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:51:19 by atucci            #+#    #+#             */
/*   Updated: 2023/03/02 12:53:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The get_next_line function reads the next line from a file descriptor (fd)
// and returns it as a string.
// It also saves the remaining text after the newline character in a static variable called 'backup'.

#include "get_next_line.h"

// ft_read_to_backup reads from file descriptor (fd) until it finds a newline character
// or reaches the end of the file. It saves the text read in the backup variable and returns it.
// If an error occurs, it returns NULL.

char *ft_read_to_backup(int fd, char *backup)
{
char *buff;
int bytes;

// Allocate memory for the buffer to read data from the file descriptor

buff = malloc(BUFFER_SIZE + 1);
if (!buff)
	return (NULL);

bytes = 1;

// Continue reading until a newline character is found or the end of file is reached

while (!ft_strchr(backup, '\n') && bytes != 0)
{

	// Read data from the file descriptor into the buffer

	bytes = read(fd, buff, BUFFER_SIZE);
	if (bytes == -1)
	{

		// If an error occurs, free the buffer and return NULL

		free(buff);
		return (NULL);
	}
	buff[bytes] = '\0';

	// Append the buffer to the backup string

	backup = ft_strjoin(backup, buff);
}


// Free the buffer and return the backup string

free(buff);
return (backup);
}


// The get_next_line function reads the next line from a file descriptor (fd)
// and returns it as a string.
// It also saves the remaining text after the newline character in a static variable called 'backup'.


char *get_next_line(int fd)
{
char *line;
static char *backup;

// If file descriptor (fd) is invalid or buffer size is less than or equal to zero, return NULL


if (fd < 0 || BUFFER_SIZE <= 0)
	return (0);


// Read from file descriptor (fd) and save the text in the backup variable


backup = ft_read_to_backup(fd, backup);
if (!backup)
	return (NULL);

// Get the line from the backup variable and save it in the line variable


line = ft_get_line(backup);

// Update the backup variable to contain the remaining text after the newline character


backup = ft_backup(backup);

// Return the line read from the file descriptor

return (line);
}
