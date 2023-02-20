/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:51:04 by atucci            #+#    #+#             */
/*   Updated: 2023/02/16 14:51:14 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *buf = NULL;
    static int buf_idx = 0;
    static int bytes_read = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    char *line = (char *) malloc(BUFFER_SIZE + 1);
    if (!line)
        return (NULL);

    int line_idx = 0;

    while (1)
    {
        if (buf_idx == bytes_read)
        {
            buf_idx = 0;
            bytes_read = read(fd, buf, BUFFER_SIZE);
            if (bytes_read <= 0)
                break;
        }

        char c = buf[buf_idx++];
        if (c == '\n')
            break;

        line[line_idx++] = c;
    }

    if (line_idx == 0)
    {
        free(line);
        return (NULL);
    }

    line[line_idx] = '\0';
    return (line);
}

