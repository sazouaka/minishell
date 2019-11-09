NAME = libft.a
SRC = *.c
HEADER = libft.h
OBJECTS = *.o

all : $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -I=./$(HEADR) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
