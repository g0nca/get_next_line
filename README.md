# Get Next Line 📄

## GRADE
![a](Screenshot from 2025-02-06 13-34-08.png)

## 📌 Description

**get_next_line** is a project aimed at implementing a function capable of reading a line from a file descriptor efficiently. This function is widely used in programs that require reading files or standard input (stdin) line by line.

## ⚙️ How It Works!

The function `get_next_line(int fd)` returns a line from the file specified by the descriptor `fd` every time it is called. The reading is done incrementally, using a dynamic buffer to store the data.

It follows these rules:
- Returns a line from the file, including `\n` if present.
- Returns `NULL` at the end of the file or in case of an error.
- Works correctly with any type of file.
- Uses a static variable to store data between successive calls.

## 🛠️ How to Compile

`get_next_line` can be compiled along with your project using a compiler like **cc**:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Here, `BUFFER_SIZE` is a macro that defines the buffer size used for reading the file. The value can be adjusted as needed.

## 🚀 Usage

Example of using `get_next_line` to read a file line by line:

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📂 Project Structure

- `get_next_line.c` → Contains the main implementation of `get_next_line`.
- `get_next_line_utils.c` → Auxiliary functions used by `get_next_line`.
- `get_next_line.h` → Header file with function declarations.
- `file.txt` → Test file for reading line by line.

## ⚠️ Rules & Restrictions

- The code must comply with **Norminette**.
- The use of dynamic allocation functions (except for `malloc`, `free`, and `read`) is prohibited.
- The function must work with different `BUFFER_SIZE` values.
