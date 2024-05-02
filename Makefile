NAME = fractol
MLX_NAME = mlx_linux/libmlx.a
MLX_GIT = mlx_linux
LIB_NAME = libft/libft.a
CFLAGS = -I/includes/
SRCS = $(addprefix sources/, fractol_main.c mandelbrot_calc.c render_mandelbrot.c init.c event_handling.c error_handling.c colors.c)
BSRCS = $(addprefix sources/, more_complex_calc_bonus.c)
OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

all: $(LIB_NAME) $(MLX_NAME) $(NAME)

$(LIB_NAME):
	$(MAKE) -C ./libft
$(MLX_NAME):
	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
	$(MAKE) -C ./mlx_linux	

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
bonus: all
$(NAME): $(MLX_NAME) $(LIB_NAME) $(OBJ) $(BOBJ)
	$(CC) $(OBJ) $(BOBJ) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean: 
	$(MAKE) clean -C./libft
	-$(MAKE) clean -C./mlx_linux
	rm -rf $(OBJ) $(BOBJ)
fclean: clean
	$(MAKE) fclean -C./libft
	rm -rf $(NAME)
	rm -rf $(MLX_GIT)
re: fclean all

.PHONY: all clean fclean re
