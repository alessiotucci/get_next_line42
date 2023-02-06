/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:39:29 by atucci            #+#    #+#             */
/*   Updated: 2023/02/06 15:13:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int fd;
	int	len;
	char *pointer; // this  pointer  is used in Read function
	static char *final;	// this pointer is used to Printf function
	int count;
	
	pointer = malloc(BUFFER_SIZE + 1);
	if (pointer == NULL)
		return (0);

	// checking the dynamic allocation of memory
	fd = open("shortsubject.txt", O_RDONLY);

	// read function allow me to read the text file
	int	bytes_read = read(fd,pointer,BUFFER_SIZE);
	// it store the information in the pointer passed as paramater
	len = strlen(pointer);
	
	// loops throught the entire text file
	// THIS IS NOT SAID IN THE SUBJECT
	while (bytes_read != 0)
	{
		// allocating the memory for final, which will contain the line with the desired char
		final = malloc(sizeof(char) * len + 1);
		if (final == NULL)
			return (0);
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
		final[count] = '\n';
		final[count + 1] = '\0';
		
		// print the result
		
		//printf( "THIS IS THE LINE\n%s", pointer);
		
		
		printf( "final:\n%s\n", final);
		// freeing and closing the  file
		// free(final);
		bytes_read = read(fd, pointer, 100);
		len = strlen(pointer);
	}
		close(fd);
	free(pointer);
	free(final);
	return (0);	
}

