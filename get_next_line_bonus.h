/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:30:30 by atucci            #+#    #+#             */
/*   Updated: 2023/03/03 14:30:35 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** The get_next_line function reads a file descriptor (fd) and returns a line
** of text from the file each time it is called, until the end of the file is
** reached. The function allocates memory for the line, which must be freed by
** the calling function.
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/*
** The BUFFER_SIZE macro determines the size of the buffer used by the function
** to read the file. It can be adjusted as needed to optimize performance.
*/

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** The get_next_line function relies on these system libraries to handle file
** I/O and dynamic memory allocation.
*/

char	*get_next_line(int fd);
char	*ft_read_to_backup(int fd, char *backup);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *backup, char *buff);
size_t	ft_strlen(const char *s);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);

#endif

