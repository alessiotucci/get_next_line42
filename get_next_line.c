/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:19:12 by atucci            #+#    #+#             */
/*   Updated: 2023/02/08 16:49:47 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_next_line(int fd)
{
	static char *pointer = NULL;// pointer to pass to the read function as parameter
	char *final;// pointer that will return
	int len;
	static int count; // counter to go throught the string
	int bytes_read;
	int i;
	if (pointer == NULL)
	{
		pointer = malloc(BUFFER_SIZE + 1);
		if (pointer == NULL)
			return (0);
	bytes_read = read(fd,pointer,BUFFER_SIZE);
	len = strlen(pointer);
	}
	else
		len = strlen(pointer + count); // this is after the  first  call of the  functio


	// allocating the memory for final, which will contain the line with the desired char
		final = malloc(sizeof(char) * (len + 1));
		if (final == NULL)
			return (0);
		i = 0;
		count = 0;
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
			pointer = realloc(pointer, sizeof(char) * (len + BUFFER_SIZE + 1));
					if (pointer == NULL)
						return (0);
			bytes_read = read (fd, pointer + len, BUFFER_SIZE);
			return (get_next_line(fd));
}
	
int	main()
{
	int fd;
	fd = open("shortsubject.txt", O_RDONLY);

		//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*//*///*////*///*///*///*///
		// print the result, ofc to print the copied line  the function has be called;

		printf( "copied line:\n%s", get_next_line(fd));
		printf( "copied line:\n%s", get_next_line(fd));
		printf( "copied line:\n%s", get_next_line(fd));
		close(fd);
	return (0);
}
