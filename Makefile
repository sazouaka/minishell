NAME = minishell
SRC_ML = ./env_tab.c ./free_tab.c ./ft_cd_old.c ./ft_echo.c ./ft_exec.c \
	./ft_parse.c ./ft_path.c ./ft_setenv.c ./get_next_line.c ./free_list.c \
	./ft_cd.c ./ft_change_d.c ./ft_env.c ./ft_len.c ./ft_parse_len.c \
	./ft_quotes_dolar.c ./ft_unsetenv.c ./get_var_val.c ./main_2.c \
	./minishell.c ./verify_type.c
LIBFTA = ./libft/libft.a
SRC_LF = ./libft/ft_putchar.c ./libft/ft_strlen.c ./libft/ft_strcmp.c ./libft/ft_strdup.c ./libft/ft_isalnum.c \
	./libft/ft_isdigit.c ./libft/ft_isalpha.c ./libft/ft_strchr.c ./libft/ft_putstr.c ./libft/ft_strnew.c \
	./libft/ft_strsub.c ./libft/ft_strjoin.c ./libft/ft_strsplit.c

HEADER = ./minishell.h
OBJ_ML = $(SRC_ML:.c=.o)
OBJ_LF = $(SRC_LF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_ML) $(OBJ_LF)
	$(MAKE) -C ./libft
	gcc -Wall -Wextra -Werror -I $(HEADER) $(SRC_ML) $(SRC_LF) $(LIBFTA) -o $(NAME)

clean :
	/bin/rm -f $(OBJ_ML)
	$(MAKE) -C ./libft/ clean

fclean : clean
	/bin/rm -f $(NAME)
	$(MAKE) -C ./libft/ fclean

re : fclean all