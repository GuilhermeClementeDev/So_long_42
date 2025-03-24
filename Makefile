# -*- MakeFile -*-

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib/libft.a

LIB_PATH = ./lib

MINILIBX_FLAGS = -Lmlx -lmlx_Linux -lX11 -lXext

MLX = make_mlx

MLX_PATH = ./mlx

MLX_LIB = ./mlx/libmlx_Linux.a

MY_SOURCES = main.c map_read.c error.c map_verify.c valid_path.c \
init_game.c ft_render.c game.c

OBJS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) ${MINILIBX_FLAGS} -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIB_PATH)

$(MLX_LIB):
	@make -C $(MLX_PATH)

clean:
	@make -C $(LIB_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all
