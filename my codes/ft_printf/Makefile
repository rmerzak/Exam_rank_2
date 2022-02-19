NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = ft_printf.h 

SOURCES = ft_printf.c\

OBJET = $(SOURCES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJET)
	ar -rcs $(NAME) $(OBJET) 

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJET)

fclean: clean
	rm -f $(NAME)

re: fclean all
