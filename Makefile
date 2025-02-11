# -*- MakeFile -*-

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib/libft.a

LIB_PATH = ./lib

MINILIBX_FLAGS = -Lmlx -lmlx_Linux -lX11 -lXext

MLX = make_mlx

MLX_PATH = ./mlx

MY_SOURCES = main.c map_read.c error.c map_verify.c valid_path.c \
init_game.c render.c

all: $(NAME)

$(NAME): $(MY_SOURCES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(MY_SOURCES) $(LIBFT) ${MINILIBX_FLAGS} -o $(NAME)

$(LIBFT):
	@make -C $(LIB_PATH)

make_mlx:
	@make -C $(MLX_PATH)

clean:
	@make -C $(LIB_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
