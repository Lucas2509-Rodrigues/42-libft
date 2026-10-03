NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= atoi.c \
		  bzero.c \
		  isalnum.c \
		  isalpha.c \
		  isascii.c \
		  isdigit.c \
		  isprint.c \
		  itoa.c \
		  memalloc.c \
		  memccpy.c \
		  memchr.c \
		  memcmp.c \
		  memcpy.c \
		  memdel.c \
		  memmove.c \
		  memset.c \
		  putchar.c \
		  putchar_fd.c \
		  putendl.c \
		  putendl_fd.c \
		  putnbr.c \
		  putnbr_fd.c \
		  putstr.c \
		  putstr_fd.c \
		  strcat.c \
		  strchr.c \
		  strclr.c \
		  strcmp.c \
		  strcpy.c \
		  strdel.c \
		  strdup.c \
		  strequ.c \
		  striter.c \
		  striteri.c \
		  strjoin.c \
		  strlcat.c \
		  strlen.c \
		  strmap.c \
		  strmapi.c \
		  strncat.c \
		  strncmp.c \
		  strncpy.c \
		  strnequ.c \
		  strnew.c \
		  strnstr.c \
		  strrchr.c \
		  strsplit.c \
		  strstr.c \
		  strsub.c \
		  strtrim.c \
		  tolower.c \
		  toupper.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
