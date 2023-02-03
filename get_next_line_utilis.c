/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:40:09 by atucci            #+#    #+#             */
/*   Updated: 2023/02/03 14:35:24 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *sour, size_t n)
{
	char	*char_dest;
	char	*char_sour;
	size_t	count;

	if (dest == 0 && sour == 0)
		return (0);
	count = 0;
	char_dest = (char *) dest;
	char_sour = (char *) sour;
	while (count < n)
	{
		char_dest[count] = char_sour[count];
		count++;
	}
	return (char_dest);
}
#include <stdlib.h>

void *my_realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	return malloc(size);
	
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	
	void *new_ptr = malloc(size);
	
	if (new_ptr == NULL)
	return (NULL);
	
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return new_ptr;
}
