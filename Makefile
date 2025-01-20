# -*- MakeFile -*-

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFTNAME = libft.a

all: $(NAME)

$(NAME): makelib

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

makelib:
	@make -C ./lib
	@cp ./lib/$(LIBFTNAME) .

clean:
	@rm -f
	@cd ./lib && make clean

fclean: clean
	@rm -f $(LIBFTNAME)
	@cd ./lib && make fclean

re: fclean all
