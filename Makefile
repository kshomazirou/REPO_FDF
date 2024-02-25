FRAMEWORKS= -lmlx -framework AppKit -framework OpenGL
FLAGS=-Wall -Wextra -Werror
NAME=fdf

SRC = src/printf/ft_printf.c \
	src/printf/ft_change_base.c \
	src/printf/ft_hexer.c \
	src/printf/ft_inter.c \
	src/printf/ft_pointer.c \
	src/printf/ft_putputstr_fd.c \
	src/printf/ft_putstr_count.c \
	src/printf/ft_tolower.c \
	src/printf/ft_putputchar_fd.c \
	src/printf/ft_uber_count.c \
	src/printf/ft_operator.c \
	src/printf/libft/ft_itoa.c \
	src/printf/libft/ft_putchar_fd.c \
	src/printf/libft/ft_putstr_fd.c \
	src/printf/libft/ft_strdup.c \
	src/printf/libft/ft_tolower.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	deal_key.c \
	draw.c \
	fdf.c \
	new_window.c \
	print_data.c \
	read_file.c \
	set_param.c \

OBJS = $(SRC:.c=.o)

INCLUDES = src/printf/libft/libft.a \
		$(FRAMEWORKS)

$(NAME):	$(OBJS)
	ar rcs fdf.a $(OBJS)
	@make -C src/printf/libft/ all
	@make -C src/printf/ all
	cc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES)

all: $(NAME)

clean:
	@make -C src/printf/libft clean
	@make -C src/printf/ clean
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
