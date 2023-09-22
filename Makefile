CC			= cc
RM			= rm -r
CFLAGS		= -g -Wall -Wextra -Werror
LFLAGS		= -L/minilibx-linux -lXext -lX11 -lm

NAME		= miniRT

HEAD		= -I./includes
HEAD_LIBMLX	= -I./minilibx-linux
SRC_DIR		= ./src
BUILD_DIR	= ./build
LIBMLX		= minilibx-linux/libmlx.a
MLX_DIR 	= minilibx-linux

SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(LFLAGS) -o $@
	cp $(BUILD_DIR)/$(NAME) .

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEAD) $(HEAD_LIBMLX) -c -o $@ $<

$(LIBMLX):
	make -C $(MLX_DIR)

all: $(LIBMLX) $(BUILD_DIR)/$(NAME)

clean:
	$(RM) $(BUILD_DIR)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re