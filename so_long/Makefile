# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlofrano <vlofrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:52:50 by vlofrano          #+#    #+#              #
#    Updated: 2023/03/07 14:59:15 by vlofrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	so_long
CC			=	gcc

OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	so_long.c

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


obj:
			@mkdir -p obj

%.o: %.c
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