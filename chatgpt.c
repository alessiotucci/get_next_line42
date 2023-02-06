
#include "get_next_line.h"

char *get_new_pointer(char *pointer, int len)
{
char *new_pointer;


new_pointer = malloc(sizeof(char) * (len + 1));
if (new_pointer == NULL)
	return (NULL);
memcpy(new_pointer, pointer, len);
new_pointer[len] = '\0';
free(pointer);
return (new_pointer);

}

char *get_final(char *pointer, int bytes_read, int len)
{
char *final;
int count;

count = 0;
final = malloc(sizeof(char) * (len + 1));
if (final == NULL)
	return (NULL);
while (pointer[count] != '\n' && bytes_read > 0)
{
	final[count] = pointer[count];
	count++;
	if (count == len)
	{
		len += bytes_read;
		pointer = get_new_pointer(pointer, len);
		if (pointer == NULL)
			return (NULL);
		bytes_read = read(fd, pointer + count, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
	}
}
final[count] = '\0';
return (final);


}

char *get_next_line(int fd)
{
char *pointer;
int bytes_read;
int len;
pointer = malloc(BUFFER_SIZE + 1);
if (pointer == NULL)
	return (NULL);
bytes_read = read(fd, pointer, BUFFER_SIZE);
if (bytes_read == -1)
	return (NULL);
if (bytes_read == 0)
{
	free(pointer);
	return (NULL);
}
len = bytes_read;
return (get_final(pointer, bytes_read, len));
} 

int main()
{
int fd;
fd = open("shortsubject.txt", O_RDONLY);
printf("THIS IS THE FIRST LINE: \n%s", get_next_line(fd));
printf("THIS IS THE SECOND LINE: \n%s", get_next_line(fd));
close(fd);
return (0);
}
