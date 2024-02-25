# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshoma <kshoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 08:23:52 by kshoma            #+#    #+#              #
#    Updated: 2023/10/16 10:05:07 by kshoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ./ft_printf.c \
		./ft_change_base.c \
		./ft_hexer.c \
		./ft_inter.c \
		./ft_pointer.c \
		./ft_putputstr_fd.c \
		./ft_putstr_count.c \
		./ft_tolower.c \
		./ft_putputchar_fd.c \
		./ft_uber_count.c \
		./ft_uber_count.c \
		./ft_operator.c \
		./libft/ft_calloc.c \
		./libft/ft_itoa.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strdup.c \
		./libft/ft_strlen.c \
		./libft/ft_tolower.c \
		./libft/ft_bzero.c \
		./libft/ft_memset.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
					rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re