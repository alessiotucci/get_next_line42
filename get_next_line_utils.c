/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:54:10 by atucci            #+#    #+#             */
/*   Updated: 2023/03/02 12:58:55 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *backup, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (backup)
		while (backup[++i] != '\0')
			str[i] = backup[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(backup) + ft_strlen(buff)] = '\0';
	free(backup);
	return (str);
}
// The ft_get_line function extracts the next line from the backup string and returns it.
// It allocates memory for the line and adds a terminating null character.
// If the backup string is empty or doesn't contain a newline character, it returns NULL.

char *ft_get_line(char *backup)
{
int i;
char *str;
i = 0;

// If the backup string is empty, return NULL
if (!backup[i])
	return (NULL);

// Find the index of the newline character in the backup string
while (backup[i] && backup[i] != '\n')
	i++;

// Allocate memory for the line, including space for the newline character and the terminating null character
str = (char *)malloc(sizeof(char) * (i + 2));
if (!str)
	return (NULL);

// Copy characters from the backup string to the line string until the newline character is encountered
i = 0;
while (backup[i] && backup[i] != '\n')
{
	str[i] = backup[i];
	i++;
}

// If the newline character is found, copy it to the line string and advance the index
if (backup[i] == '\n')
{
	str[i] = backup[i];
	i++;
}

// Add a terminating null character to the line string
str[i] = '\0';

// Return the line string
return (str);
}
// The ft_backup function updates the backup string to contain the remaining text after the newline character.
// It allocates memory for the updated backup string and frees the original backup string.
// If the backup string doesn't contain a newline character, it frees the backup string and returns NULL.

char *ft_backup(char *backup)
{
int i;
int j;
char *str;
i = 0;

// Find the index of the newline character in the backup string
while (backup[i] && backup[i] != '\n')
	i++;

// If the backup string doesn't contain a newline character, free the backup string and return NULL
if (!backup[i])
{
	free(backup);
	return (NULL);
}

// Allocate memory for the updated backup string, excluding the characters before the newline character
str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
if (!str)
	return (NULL);

// Copy characters from the backup string after the newline character to the updated backup string
i++;
j = 0;
while (backup[i])
	str[j++] = backup[i++];

// Add a terminating null character to the updated backup string
str[j] = '\0';

// Free the original backup string and return the updated backup string
free(backup);
return (str);
}
