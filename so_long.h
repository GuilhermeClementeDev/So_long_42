#ifndef SO_LONG_H
# define SO_LONG_H

#include "lib/libft.h"
#include <fcntl.h>

void	ft_check_input(int argc, char **argv);

void	ft_error(char *str, int n);

void	ft_read_file(char *argv);

#endif
