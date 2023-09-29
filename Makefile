NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra
#CFLAGS += -g -fsanitize=address

MINILIBX_DIR = minlibx-linux
INCLUDES_DIR = includes
INCLUDES =  -I$(INCLUDES_DIR) -I$(MINILIBX_DIR)

SRCS_DIR = src
SRCS = $(SRCS_DIR)/main.c

OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

RM = rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
