# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 10:12:09 by ryhara            #+#    #+#              #
#    Updated: 2023/06/11 12:00:12 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FT_PRINTF_NAME = libftprintf.a
FT_PRINTF_DIR = ./stdio/ft_printf/

FT_DPRINTF_NAME = libftdprintf.a
FT_DPRINTF_DIR = ./stdio/ft_dprintf/

CC = cc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_DEBUG
	CFLAGS += -g -fsanitize=address
endif

CTYPE_SRC = ft_isalpha.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isdigit.c \
	ft_isdouble.c \
	ft_isint.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_toupper.c \
	ft_tolower.c
CTYPE_SRCS = $(addprefix ctype/, $(CTYPE_SRC))

DOUBLE_LIST_SRC = ft_dlst_delete.c \
	ft_dlst_free_all.c \
	ft_dlst_head_init.c \
	ft_dlstadd_back.c \
	ft_dlstadd_front.c \
	ft_dlstinsert_back.c \
	ft_dlstinsert_front.c \
	ft_dlstnew.c \
	ft_dlstsize.c
DOUBLE_LIST_SRCS = $(addprefix doubly_linked_list/, $(DOUBLE_LIST_SRC))

SINGLE_LIST_SRTC = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstnew.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstsize.c
SINGLE_LIST_SRCS = $(addprefix singly_linked_list/, $(SINGLE_LIST_SRTC))

STDIO_SRC = ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c
STDIO_SRCS = $(addprefix stdio/, $(STDIO_SRC))

STDLIB_SRC = ft_atof.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_itoa.c \
	ft_strtol.c
STDLIB_SRCS = $(addprefix stdlib/, $(STDLIB_SRC))

STRING_SRC = ft_bzero.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_split_charset.c \
	ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c
STRING_SRCS = $(addprefix string/, $(STRING_SRC))

SRCS = $(CTYPE_SRCS) $(DOUBLE_LIST_SRCS) $(SINGLE_LIST_SRCS) $(STDIO_SRCS) $(STDLIB_SRCS) $(STRING_SRCS)
OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
OBJDIR = ./obj/

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
BLUE		= \033[1;34m
RESET		= \033[0m

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@ echo  "$(CHECK) $(BLUE) compiling $(FT_PRINTF_NAME) ... $(RESET)"
	@ make -C ./stdio/ft_printf
	@ mv $(FT_PRINTF_DIR)$(FT_PRINTF_NAME) ./
	@ echo "$(CHECK) $(BLUE) compiling $(FT_DPRINTF_NAME) ... $(RESET)"
	@ make -C ./stdio/ft_dprintf
	@ mv $(FT_DPRINTF_DIR)$(FT_DPRINTF_NAME) ./
	@ echo "$(CHECK) $(BLUE)compiling $(NAME) ...$(RESET)"
	@ $(AR) $@ $^


$(OBJDIR):
	@ mkdir -p obj/ctype obj/doubly_linked_list obj/singly_linked_list
	@ mkdir -p obj/stdio obj/stdio/get_next_line obj/stdlib obj/string

$(OBJDIR)%.o : %.c
	@ $(CC) $(CFLAGS)  -o $@ -c $<

clean :
	@ echo "$(REMOVE) $(BLUE) cleaning $(FT_PRINTF_NAME) $(FT_DPRINTF_NAME) $(NAME) ... $(RESET)"
	@ make clean -C ./stdio/ft_printf
	@ make clean -C ./stdio/ft_dprintf
	@ $(RM) $(OBJDIR)

fclean : clean
	@ echo "$(REMOVE) $(BLUE) fcleaning $(FT_PRINTF_NAME) $(FT_DPRINTF_NAME) $(NAME) ... $(RESET)"
	@ $(RM) $(NAME) $(FT_PRINTF_NAME) $(FT_DPRINTF_NAME)

re : fclean all

debug :
	make WITH_DEBUG=1

.PHONY : all clean fclean re