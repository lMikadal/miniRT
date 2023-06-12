# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmikada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 16:08:19 by pmikada           #+#    #+#              #
#    Updated: 2022/10/08 16:08:23 by pmikada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = cc

NAME = miniRT

# SRCS = map.c
SRCS = setting.c \
	utils/ft_free.c \
	utils/ft_split.c \
	utils/ft_utils.c

G_N_L = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

# LIBX = minilibx_macos/mlx_shaders.c minilibx_macos/mlx_new_window.m minilibx_macos/mlx_init_loop.m minilibx_macos/mlx_new_image.m \
# 		minilibx_macos/mlx_xpm.c minilibx_macos/mlx_int_str_to_wordtab.c

OBJS = $(SRCS:.c=.o)

OBJS_G_N_L = $(G_N_L:.c=.o)

OBJS_LIBX = $(LIBX:.c=.o)
# OBJS_LIBX_M = $(OBJS_LIBX:.m=.o)

all: $(NAME)

# $(NAME): $(OBJS) $(OBJS_G_N_L) $(OBJS_LIBX_M)
# 	$(GCC) -Wall -Wextra -Werror main.c *.o get_next_line/*.o minilibx_macos/*.o -framework OpenGL -framework AppKit -o $(NAME)
$(NAME): $(OBJS) $(OBJS_G_N_L) 
	$(GCC) -Wall -Wextra -Werror main.c *.o utils/*.o get_next_line/*.o -o $(NAME)

clean:
	rm -rf *.o
	rm -rf get_next_line/*.o
	rm -rf utils/*.o
	rm -rf minilibx_macos/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

# test: $(OBJS) $(OBJS_G_N_L)
# 	$(GCC) -Wall -Werror -Wextra main.c ./*.o get_next_line/*.o -o $(NAME)

# retest: fclean test

.PHONY: all clean fclean re
