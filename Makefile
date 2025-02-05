# -*- MakeFile -*-

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib/libft.a

LIB_PATH = ./lib

MY_SOURCES = main.c map_read.c error.c map_verify.c valid_path.c

all: $(NAME)

$(NAME): $(MY_SOURCES) $(LIBFT)
	@$(CC) $(CFLAGS) $(MY_SOURCES) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIB_PATH)

clean:
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
