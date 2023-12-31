NAME = miniRT
CC = cc
CFLAGS = -Wall -Werror -Wextra

ifdef WITH_DEBUG
	CFLAGS += -g -fsanitize=address
endif

INCLUDES_DIR = include
MINILIBX_DIR = mlx
X11_DIR = /usr/X11

LIBFT_DIR = libft
LIBFT_FLAGS = libft/libft.a libft/libftprintf.a libft/libftdprintf.a

INCLUDES =  -I$(INCLUDES_DIR) -I$(MINILIBX_DIR) -I$(X11_DIR)/include -I$(LIBFT_DIR)/includes -I$(LIBFT_DIR)/stdio/ft_dprintf -I$(LIBFT_DIR)/stdio/ft_printf
MINILIBX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


SRCS_DIR = src
SRC = main.c \
	parse.c \
	parse_check.c \
	parse_objs.c \
	parse_utils.c \
	parse_settings.c \
	objs_newnode.c \
	objs_utils.c \
	init.c \
	try_calloc.c \
	try_malloc.c \
	error.c	\
	render.c	\
	vector3d.c	\
	vector3d_utils.c	\
	sphere.c	\
	color.c	\
	get_radiance.c	\
	get_incidence_dot.c  \
	vector3d_utils2.c	\
	sphere.c \
	cylinder.c \
	cylinder_utils.c \
	get_camera_ray.c \
	free.c	\
	render_loop.c	\
	shadow.c	\
	plane.c	\
	mlx_key.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRC));

OBJS_DIR = obj
OBJS = $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

RM = rm -rf

all: $(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(MINILIBX_DIR)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(MINILIBX_FLAGS) $(INCLUDES) $(LIBFT_FLAGS) -o $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

debug: fclean
	make WITH_DEBUG=1

files:	all
	@bash -c 'for f in files/my_test/*; do echo $$f; ./miniRT $$f; echo; done;'

test:	all
	@echo "------------------test start------------------"
	@bash -c 'for f in files/ng/*; do echo $$f; ./miniRT $$f; echo; done;'
	@echo "------------------test end------------------"

.PHONY: all fclean clean re debug test files
