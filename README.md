<h1 align="center">libft</h1>

<p align="center">
  <em>My first C library, built from scratch as part of the <a href="https://42.fr">42</a> common core.</em>
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/language-C-00599C?logo=c&logoColor=white">
  <img alt="Norminette" src="https://img.shields.io/badge/norminette-passing-brightgreen">
  <img alt="Functions" src="https://img.shields.io/badge/functions-52-informational">
  <img alt="School" src="https://img.shields.io/badge/school-42-000000">
</p>

---

## About

`libft` is a static C library that re-implements a set of standard `libc` functions
and adds a collection of useful string, memory and output helpers. It is the first
project of the 42 curriculum and is reused as a foundation in many later projects.

The goal is to understand how these functions really work: pointer arithmetic, memory
management, edge cases, and how to build and ship a library with a `Makefile`.

**Constraints of the project**

- Only `malloc`, `free` and `write` are allowed from the system.
- No global variables; helper functions are `static`.
- Code follows the [42 Norm](https://github.com/42School/norminette) (checked with `norminette`).
- No crashes, no leaks: every allocation is freed by the caller using the provided helpers.
- Compiled with `-Wall -Wextra -Werror`.

## Status

| Part | State |
| --- | --- |
| Part 1: libc functions | Done (28 functions) |
| Part 2: additional functions | Done (24 functions) |
| Bonus (linked lists) | Not implemented yet |

## Functions

### Part 1: libc re-implementations

| Category | Functions |
| --- | --- |
| Memory | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memccpy` `ft_memmove` `ft_memchr` `ft_memcmp` |
| Strings | `ft_strlen` `ft_strdup` `ft_strcpy` `ft_strncpy` `ft_strcat` `ft_strncat` `ft_strlcat` |
| Searching | `ft_strchr` `ft_strrchr` `ft_strstr` `ft_strnstr` |
| Comparing | `ft_strcmp` `ft_strncmp` |
| Conversion | `ft_atoi` `ft_toupper` `ft_tolower` |
| Character checks | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |

### Part 2: additional functions

| Category | Functions |
| --- | --- |
| Memory | `ft_memalloc` `ft_memdel` |
| String lifecycle | `ft_strnew` `ft_strdel` `ft_strclr` |
| Iteration and mapping | `ft_striter` `ft_striteri` `ft_strmap` `ft_strmapi` |
| Comparison | `ft_strequ` `ft_strnequ` |
| Building strings | `ft_strsub` `ft_strjoin` `ft_strtrim` `ft_strsplit` `ft_itoa` |
| Output | `ft_putchar` `ft_putstr` `ft_putendl` `ft_putnbr` |
| Output to a file descriptor | `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` |

The full list of prototypes is in [`libft.h`](libft.h).

## Build

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # rebuilds everything from scratch
```

The `Makefile` only recompiles files that changed and does not relink when nothing
changed.

## Usage

Include the header and link against the library:

```c
#include "libft.h"

int main(void)
{
    char    *str;

    str = ft_itoa(-42);
    ft_putendl(str);        /* prints: -42 */
    ft_strdel(&str);        /* frees and sets str to NULL */
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o demo
./demo
```

## Project layout

Following the subject, all sources, the header and the `Makefile` live at the root of the repository.

```
.
├── libft.h        # prototypes
├── Makefile       # builds libft.a
├── author         # 42 login
├── *.c            # one function per file (atoi.c, strsplit.c, ...)
└── README.md
```

## How I tested it

- `norminette` on every source file and on the header.
- Builds cleanly with `-Wall -Wextra -Werror`.
- Behaviour compared with the real `libc` for the standard functions, including edge cases
  (`INT_MIN`, empty strings, `n = 0`, overlapping buffers in `ft_memmove`, `\0` handling).
- Run under AddressSanitizer and UndefinedBehaviorSanitizer to catch invalid memory access
  and undefined behaviour.

## What I learned

- How memory really behaves in C: pointers, casts, `const` correctness and overlapping copies.
- Writing defensive code: `NULL` checks and cleaning up when an allocation fails midway
  (see `ft_strsplit`).
- Structuring a multi-file project, writing a `Makefile` with proper dependencies, and
  building a static library with `ar`.
- Working within strict coding rules (the Norm) and peer review.

## Author

**Lucas**, student at [42](https://42.fr).
