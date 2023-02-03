/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:39:29 by atucci            #+#    #+#             */
/*   Updated: 2023/02/03 15:10:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
// library to use open
#include <stdlib.h>
// library to use malloc 
#include <unistd.h>
// library to use read  
#include <stdio.h>
// library to use Printf for testing
#include <strings.h>
// library to use strlen for testing 
int main()
{
	int fd;
	int	len;
	 char *pointer; // this  pointer  is used in Read function
	char *final;	// this pointer is used to Printf function
	int count;
	
	pointer = malloc(sizeof(char) * 100);
	if (pointer == NULL)
		return (0);

	printf( "pointer address: %p\n", pointer);
	// checking the dynamic allocation of memory
	fd = open("shortsubject.txt", O_RDONLY);
	int fd1 = open("testo.txt", O_RDONLY);
	
	// this is just to understand the file descriptor
	printf( "this is  the file  descriptor: %d\n", fd);
	printf( "this is  the file  descriptor: %d\n", fd1);

	// read function allow me to read the text file
	int	bytes_read = read(fd,pointer,50);
	// it store the information in the pointer passed as paramater
	len = strlen(pointer);
	
	// loops throught the entire text file
	while (bytes_read != 0)
	{
		// allocating the memory for final, which will contain the line with the desired char
		final = malloc(sizeof(char) * len + 1);
		if (final == NULL)
			return (0);
		printf( "final address: %p\n", final);
		count = 0;
		while (pointer[count] != '\n')
		{
			final[count] = pointer[count];
			count++;
			// if the end of pointer is reached, allocate more memory and read 
			// the next chuck of memory
				if (count == len)
				{
					len += 100;
					pointer = realloc(pointer, sizeof(char) * (len + 1));
					if (pointer == NULL)
						return (0);
				read (fd, pointer + count, 100);
				}
		}
	
		// add null terminator to the final
		final[count] = '\0';
		
		// print the result
		printf( "this is the line: %s", pointer);
		printf( "lenght: %d\n", len);
		printf( "%s", final);
		// freeing and closing the  file
		free(final);
		bytes_read = read(fd, pointer, 100);
		len = strlen(pointer);
	}
		close(fd);
	free(pointer);
	return (0);	
}

