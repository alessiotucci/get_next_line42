  ### Four Day plan
  
# Day 1:
Study and understand the requirements and the basics of file handling in C, especially the open and read functions. You should also familiarize yourself with the prototypes and descriptions of the functions that are allowed to be used in this project (read, malloc, free).

* The open function in C is used to open a file and get a file descriptor, which is an integer that can be used to identify the file. The file descriptor is returned by the open function and is used to read or write to the file. 

## The basic syntax of the open function in C is:
```c
int open(const char *pathname, int flags);
```
where pathname is the path of the file you want to open and flags are the options for how you want to open the file. Some common flags include:

O_RDONLY: Open the file for reading only.

O_WRONLY: Open the file for writing only.

O_RDWR: Open the file for both reading and writing.

O_CREAT: Create the file if it doesn't exist.

O_TRUNC: Truncate the file if it already exists.

The open function returns a file descriptor if the file is successfully opened, otherwise it returns -1 to indicate an error.

It is important to close the file after you are done reading or writing to it, otherwise it may cause a resource leak. This can be done using the close function, which takes the file descriptor as an argument.

Example:
```c
#include <fcntl.h>
#include <stdio.h>

int main() {
  int fd;

  fd = open("sample.txt", O_RDONLY);
  if (fd == -1) {
    printf("Error opening file\n");
    return 1;
  }
  printf("File opened successfully\n");
  close(fd);
  return 0;
}
```

### The read function in C programming language is used to read data from a file or other input device. It takes three arguments:
```c
ssize_t read(int fd, void *buf, size_t count);
```

where fd is the file descriptor returned by the open function, buf is a pointer to a buffer where the read data will be stored, and count is the maximum number of bytes to be read.

The read function returns the number of bytes read, or -1 on error. If the end of the file has been reached, the function will return 0.

It is important to note that the buf argument must be a pointer to a memory location that is large enough to store the amount of data specified in count. If the buffer is not large enough, the read function may cause a buffer overflow, leading to unpredictable results.

Example:
```c #include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd;
  char buf[100];
  ssize_t bytes_read;

  fd = open("sample.txt", O_RDONLY);
  if (fd == -1) {
    printf("Error opening file\n");
    return 1;
  }
  bytes_read = read(fd, buf, 100);
  if (bytes_read == -1) {
    printf("Error reading file\n");
    return 1;
  }
  buf[bytes_read] = '\0';
  printf("Read %ld bytes: %s\n", bytes_read, buf);
  close(fd);
  return 0;
}
```
In this example, the read function is used to read data from a file called "sample.txt". The fd argument is the file descriptor returned by the open function, and buf is a buffer where the read data will be stored. The count argument is set to 100, meaning that up to 100 bytes will be read. If the read is successful, the number of bytes read is stored in the bytes_read variable. The buffer is then printed to the console, with a null terminator added to the end to indicate the end of the string.


# Day 2:
Start writing the  [get_next_line.c](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line.c) function by allocating memory for the line to be read and using the read function to get the data from the file. Make sure to also implement a mechanism to determine when a line has been completely read, such as checking for the newline character.

# Day 3:
Test your get_next_line function with different files and inputs to ensure it works as expected and returns the correct output. Debug and fix any issues that may arise.

# Day 4:
Optimize your code to improve its performance and efficiency, if necessary. Write comments and documentation for your code to make it readable and understandable for others. Make any final touches and clean up your code.

Note: This is just a suggested working plan and can be adjusted based on individual needs and speed. The most important thing is to understand the requirements and the basics of file handling in C before starting the implementation.
  
  
  
| function name | Description | 
 | ----------------------------- | ------------------------------------------------- | 
| [`get_next_line.c`](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line.c) | description |
| [`get_next_line.h`](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line.h) | description | 
| [`get_next_line_bonus.c`](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line_bonus.c) | description | 
| [`get_next_line_bonus.h`](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line_bonus.h) | description |  
| [`get_next_line_utils.c`](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line_utils.c) | description |
| [`get_next_line_utils_bonus.c`](https://github.com/alessiotucci/get_next_line/blob/master/get_next_line_utils.c) | description | 
| [`My original version`](https://github.com/alessiotucci/get_next_line/blob/master/original_version.c) | In my original version, I had a static int that works as counter and helps me iterate throught the string, but the function was too long for Norminette so I was forced to change approach |  
