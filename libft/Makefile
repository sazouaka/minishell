NAME = libft.a
SRC = ./ft_putchar.c ./ft_strlen.c ./ft_strcmp.c ./ft_strdup.c ./ft_isalnum.c \
	./ft_isdigit.c ./ft_isalpha.c ./ft_strchr.c ./ft_putstr.c ./ft_strnew.c \
	./ft_strsub.c ./ft_strjoin.c ./ft_strsplit.c
HEADER = ./libft.h
OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	gcc -Wall -Wextra -Werror -I $(HEADER) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
