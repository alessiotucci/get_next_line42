/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:51:04 by atucci            #+#    #+#             */
/*   Updated: 2023/03/03 15:28:15 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function reads a file line by line and returns the line
** It stores the static pointer variable which contains the string
** to be read from the file. The static count variable keeps
** track of how much of the pointer variable has been read.
**
** fd: file descriptor for the file to be read
**
** Returns:
** - a pointer to the line read from the file
** - NULL if there was an error or end of file is reached
*/

char *get_next_line(int fd)
{
static char *pointer = NULL; // static pointer variable stores the string to be read
static int count = 0; // static count variable keeps track of how much of the pointer variable has been read
int len;
int bytes_read;
char *final;
int i;
if (fd < 0 || BUFFER_SIZE < 0) // checking for invalid file descriptor or buffer size
	return (NULL);

if (!pointer) // if pointer is null, read from the file and store it in the pointer variable
{
	pointer = malloc(BUFFER_SIZE + 1);
	if (!pointer)
		return (NULL);
	bytes_read = read(fd, pointer, BUFFER_SIZE);
	if (bytes_read == -1 || bytes_read == 0)
		return (NULL);
	len = ft_strlen(pointer);
}
else // if pointer is not null, calculate the length of the string in pointer after the count position
	len = ft_strlen(pointer + count);

final = malloc(sizeof(char) * (len + 1)); // allocate memory for the final line to be returned
if (!final)
{
	free(pointer);
	return (NULL);
}

i = 0;
while (i < len) // read the line until the end or a newline character is found
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

count += len; // update the count variable with the length of the final string read

//gpt fix
final[i] = '\0'; // making sure final is always null terminated

if (!pointer) // if pointer is null, reallocate memory for it
	pointer = realloc(pointer, sizeof(char) * (len + BUFFER_SIZE + 1));
if (!pointer)
{
	free(final);
	return (NULL);
}
bytes_read = read(fd, pointer + len, BUFFER_SIZE); // read more from the file into the pointer variable
if (bytes_read <= 0) // if end of file is reached, return the last line if it is not empty
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
return (get_next_line(fd)); // recursively call the function to read the next line
}
