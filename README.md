_This project has been created as part of the 42 curriculum by lurodri2._

# libft

## Description

`libft` is my first C library, written from scratch for the 42 common core. The goal is
to re-implement a set of standard `libc` functions, add some extra utility functions, and
package everything in a static library (`libft.a`) that can be reused in later projects.

The project teaches how these functions really work: pointer arithmetic, memory
management, edge cases, and how to build and ship a library with a `Makefile`.

### Library overview

The library has 43 functions, each in its own `ft_*.c` file, with all prototypes in `libft.h`.

**Part 1: libc functions** (re-implemented with the same behaviour as the originals)

| Category         | Functions                                                                                            |
| ---------------- | ---------------------------------------------------------------------------------------------------- |
| Character checks | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint`                                     |
| Case conversion  | `ft_toupper` `ft_tolower`                                                                            |
| Memory           | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` `ft_calloc`                  |
| Strings          | `ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strdup` |
| Conversion       | `ft_atoi`                                                                                            |

**Part 2: additional functions** (not in libc, or in a different form)

| Function                                                         | What it does                                                                            |
| ---------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| `ft_substr`                                                      | Returns a new string extracted from `s`, starting at `start`, at most `len` characters. |
| `ft_strjoin`                                                     | Returns a new string made of `s1` followed by `s2`.                                     |
| `ft_strtrim`                                                     | Returns a copy of `s1` without the characters of `set` at the beginning and at the end. |
| `ft_split`                                                       | Splits a string by a delimiter character into a `NULL`-terminated array of new strings. |
| `ft_itoa`                                                        | Converts an integer to a newly allocated string.                                        |
| `ft_strmapi`                                                     | Applies a function to every character (with its index) and returns the new string.      |
| `ft_striteri`                                                    | Applies a function to every character (with its index) of a string, in place.           |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a char, a string, a string and a newline, or an integer to a file descriptor.     |

**Part 3: linked lists** (using `t_list`, with `content` and `next`)

`ft_lstnew` `ft_lstadd_front` `ft_lstadd_back` `ft_lstsize` `ft_lstlast`
`ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap`

**Project rules**

- Only `malloc`, `free` and `write` are used from the system.
- No global variables; helper functions are `static`.
- Compiled with `-Wall -Wextra -Werror` and checked with `norminette`.
- No relink: `make` does nothing when nothing changed.

## Instructions

### Build

```bash
make          # builds libft.a
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # rebuilds everything from scratch
```

### Usage

Include the header in your code and link against the library:

```c
#include "libft.h"

int main(void)
{
    char    *str;

    str = ft_itoa(-42);
    ft_putendl_fd(str, 1);   /* prints: -42 */
    free(str);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -I. -o test
./test
```

### How it was tested

- `norminette` on every source file and on the header.
- Clean build with `-Wall -Wextra -Werror`.
- Behaviour compared with the real `libc` for the standard functions, including edge
  cases (`INT_MIN`, empty strings, `n = 0`, overlapping buffers in `ft_memmove`, `NULL`
  arguments, allocation overflow in `ft_calloc`).
- Runs under AddressSanitizer, UndefinedBehaviorSanitizer and LeakSanitizer.
- Simulated `malloc` failures in the functions that allocate (`ft_split`, `ft_lstmap`,
  `ft_strjoin`, ...) to check that everything is cleaned up.
- Hand-written tests for the list functions, printing the list and the node addresses
  to verify the links.

## Resources

- The libft subject (42 curriculum).
- The `man` pages of the re-implemented functions (`man 3 strlcpy`, `man 3 calloc`, ...).
- The 42 Norm and `norminette`.
- Documentation on linked lists, pointers to pointers and dynamic memory in C.

### Use of AI

I used Claude as a tutor, not as a code generator. All the code in this repository was
written by me. The AI was used for:

- **Explaining concepts**: pointers and pointers to pointers (why `ft_lstadd_front`
  receives a `t_list **`), `size_t` and unsigned wraparound, `void` versus `void *`,
  the difference between copying a pointer and copying its content, use-after-free and
  double free.
- **Guiding my debugging**: reading compiler errors and sanitizer reports, and giving
  hints and parallel examples instead of the solution, so I could fix my code myself.
- **Reviewing my code**: pointing out edge cases and bugs in functions I had already
  written (for example in `ft_strlcat`, `ft_split` and `ft_lstclear`).
- **Testing**: running a large number of tests (comparison with `libc`, edge cases,
  AddressSanitizer/UBSan/LeakSanitizer, simulated allocation failures) and teaching me
  how to write my own tests, such as a `print_list` helper for the list functions.
- **Checking the project against the subject**: Makefile rules, `libft.h` prototypes and
  the list of required functions.

Formatting for the Norm and all final decisions about the code were done by me.
