/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:39:45 by atucci            #+#    #+#             */
/*   Updated: 2023/02/20 18:19:14 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
// library to use Printf for testing
#include <strings.h>
// library to use strlen for testing
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
// define the buffer size
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif
char 	*get_next_line(int fd);
void 	*my_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dest, const void *sour, size_t n);
size_t	ft_strlen(const char *str);

#endif
