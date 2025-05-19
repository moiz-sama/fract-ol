CC = cc 
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx_Linux -lXext -lX11 -lm

SRC = main.c ft_utils.c ft_check_args.c

OBJ = $(SRC:.c=.o)

NAME = fractol

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all