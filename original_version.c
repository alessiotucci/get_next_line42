/**

get_next_line - function that returns a line read from a file descriptor

@fd: file descriptor to read from

Return: returns the line read or NULL if end of file has been reached or an error occurred
*/
char *get_next_line(int fd)
{
static char *pointer = NULL; // static variable to store buffer between function calls
static int count = 0; // static variable to keep track of the index of pointer where the next read should start
int len; // length of the line read
int bytes_read; // number of bytes read from the file
char *final; // the final line to be returned
int i; // index variable for the final line array

// check if file descriptor or BUFFER_SIZE is invalid
if (fd < 0 || BUFFER_SIZE < 0)
return (NULL);

// if pointer is NULL, allocate memory for pointer and read the first BUFFER_SIZE bytes from the file
if (!pointer)
{
pointer = malloc(BUFFER_SIZE + 1);
if (!pointer)
return (NULL);
bytes_read = read(fd, pointer, BUFFER_SIZE);
if (bytes_read == -1 || bytes_read == 0)
return (NULL);
len = ft_strlen(pointer);
}
else
len = ft_strlen(pointer + count);

// allocate memory for the final line array
final = malloc(sizeof(char) * (len + 1));
if (!final)
{
free(pointer);
return (NULL);
}

// copy the line read from pointer to final
i = 0;
while (i < len)
{
if (pointer[count + i] == '\n') // if new line character is encountered
{
final[i] = '\n';
final[i + 1] = '\0'; // null terminate the final line array
count += i + 1; // update the count to start from the next line
return (final); // return the final line read
}
final[i] = pointer[count + i];
i++;
}

count += len; // update count to start from the next line

// if the end of pointer is reached, reallocate memory for pointer and read the next BUFFER_SIZE bytes
if (!pointer)
pointer = realloc(pointer, sizeof(char) * (len + BUFFER_SIZE + 1));
if (!pointer)
{
free(final);
return (NULL);
}
bytes_read = read(fd, pointer + len, BUFFER_SIZE);

// if no bytes are read, check if final line is null terminated and return it if it is, otherwise free memory and return NULL
if (bytes_read <= 0)
{
if (final && ft_strlen(final) > 0) // my fix
{
final[i] = '\0'; // null terminate the final line array
free(pointer);
pointer = NULL;
return (final);
}
free(pointer);
free(final);
return (NULL);
}

// recursively call the function to read the next line
return (get_next_line(fd));
}




