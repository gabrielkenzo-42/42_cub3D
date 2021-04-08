# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 04:53:19 by gkenzo-s          #+#    #+#              #
#    Updated: 2021/02/24 04:53:21 by gkenzo-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -lmlx -lm -lX11 -lXext -lbsd

NAME = cub3D

SRCS = cub3d.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@rm -rf cub3D
	@$(MAKE) bonus -C ./libft
	@gcc -g $(OBJS) -I./headers -Lmlx_linux -L/usr/lib -Imlx_linux -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)
	@rm -f cub3D.bmp

re: fclean all

bonus: all
