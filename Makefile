NAME = cub3D

SRCS = main.c \
		check_map.c \
		check_texture.c \
		parse_map.c \
		parse_texture.c \
		utils.c
      


OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft #$(FSANTIZE)
FSANTIZE = -fsanitize=address -g3
all: $(NAME)

$(NAME): $(OBJS) libft minilibx
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

minilibx:
	make -C minilibx-linux

libft:
	make -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
