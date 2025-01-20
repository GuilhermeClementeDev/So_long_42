# -*- MakeFile -*-

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib/libft.a

LIB_PATH = ./lib

MY_SOURCES = map_handler.c

OBJ = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ): $(MY_SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_PATH)

clean:
	@rm -f $(OBJ)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
