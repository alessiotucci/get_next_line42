/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:39:29 by atucci            #+#    #+#             */
/*   Updated: 2023/02/02 14:58:43 by atucci           ###   ########.fr       */
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
	char *pointer;
	char *final;
	int count;
	pointer = malloc(sizeof(char) * 50);
	if (pointer == NULL)
		return (0);
	fd = open("shortsubject.txt", O_RDONLY);
	int fd1 = open("testo.txt", O_RDONLY);
	printf( "this is  the file  descriptor: %d\n", fd);
	printf( "this is  the file  descriptor: %d\n", fd1);

	read(fd,pointer,5);
	len = strlen(pointer);
	final = malloc(sizeof(char) * len);
	count = 0;
	while (pointer[count] != 'w')
	{
		final[count] = pointer[count];
		count++;
	}
	final[count] = '\0';
	printf( "this is the line: %s", pointer);
	printf( "lenght: %d\n", len);
	printf( "s  %s", final);
	free(pointer);
	close(fd);
}

