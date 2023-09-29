NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS += -g -fsanitize=address

MINILIBX_DIR = minilibx-linux
INCLUDES_DIR = include
X11_DIR = /usr/X11
INCLUDES =  -I$(INCLUDES_DIR) -I$(MINILIBX_DIR) -I$(X11_DIR)/include
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -L$(X11_DIR)/lib -lX11 -lXext
MINILIBX_FILE = $(MINILIBX_DIR)/libmlx.a

SRCS_DIR = src
SRCS = $(SRCS_DIR)/main.c

OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

RM = rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) $(INCLUDES) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
