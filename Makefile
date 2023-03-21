# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:52:50 by vlofrano          #+#    #+#              #
#    Updated: 2023/03/16 15:24:17 by vlofrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I  ./ft_printf -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -L ./ft_printf
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=   src/so_long.c src/read_map.c  src/init.c src/util_map.c src/get_next_line.c\
				src/put_images.c src/key_hook.c src/move.c   src/win.c   src/check_contents.c src/animation.c \
						./ft_printf/ft_printf.c \
		./ft_printf/ft_printchar.c \
		./ft_printf/hex_util.c \
		./ft_printf/ft_putnbr.c \
		./ft_printf/ft_putchar.c \
		./ft_printf/ptr_print.c\
		./ft_printf/ft_putstr.c \

all:		$(MLX)  $(LFT)  obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(LFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"




$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"




obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft 
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all

.PHONY:		all clean fclean re