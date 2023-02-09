/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:19:24 by atucci            #+#    #+#             */
/*   Updated: 2023/02/09 16:19:36 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
static char *pointer = NULL;
static int count = 0;
int len;
int bytes_read;
char *final;
int i;
    
    if (fd < 0 || BUFFER_SIZE < 0)
    return (NULL);
if (!pointer)
{
    pointer = malloc(BUFFER_SIZE + 1);
    if (!pointer)
        return (NULL);
    bytes_read = read(fd, pointer, BUFFER_SIZE);
    if (bytes_read == -1 || bytes_read == 0)
        return (NULL);
    len = strlen(pointer);
}
else
    len = strlen(pointer + count);

final = malloc(sizeof(char) * (len + 1));
if (!final)
{
    free(pointer);
    return (NULL);
}

i = 0;
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
if (!pointer)
    pointer = realloc(pointer, sizeof(char) * (len + BUFFER_SIZE + 1));
if (!pointer)
{
    free(final);
    return (NULL);
}
bytes_read = read(fd, pointer + len, BUFFER_SIZE);
    if (bytes_read == 0 || bytes_read == -1)
    {
        free(pointer);
        free(final);
        return (NULL);
    }

return (get_next_line(fd));
}
