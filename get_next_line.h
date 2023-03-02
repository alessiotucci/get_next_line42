/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:02:27 by atucci            #+#    #+#             */
/*   Updated: 2023/03/02 13:02:36 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000 // define a default buffer size if not already defined
# endif

# include <unistd.h> // include library for read() and write() functions
# include <stdlib.h> // include library for malloc() and free() functions
# include <strings.h> // include library for bzero() function
# include <fcntl.h> // include library for open() function
# include <stdio.h> // include library for printf() function

char	*get_next_line(int fd); // function prototype for get_next_line function
char	*ft_read_to_backup(int fd, char *backup); // function prototype for reading data from file descriptor and storing in backup buffer
char	*ft_strchr(char *s, int c); // function prototype for searching a character in a string
char	*ft_strjoin(char *backup, char *buff); // function prototype for concatenating two strings
size_t	ft_strlen(const char *s); // function prototype for finding the length of a string
char	*ft_get_line(char *backup); // function prototype for extracting a line from the backup buffer
char	*ft_backup(char *backup); // function prototype for updating the backup buffer after a line is extracted

#endif

