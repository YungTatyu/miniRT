# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 12:42:49 by ryhara            #+#    #+#              #
#    Updated: 2023/09/29 14:09:16 by ryhara           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftdprintf.a
SRCS = ft_dprintf.c \
	ft_dputchar.c \
	ft_dputnbr_base.c \
	ft_dputnbr.c \
	ft_dputstr.c \
	ft_dputui.c \
	ft_dputaddress.c \

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)
OBJDIR = ./obj/
CC = cc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

all : $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@ $(AR) $@ $^

$(OBJDIR):
	@ mkdir obj

$(OBJDIR)%.o: %.c
	@ $(CC) $(CFLAGS)  -o $@ -c $<

clean :
	@ $(RM) $(OBJDIR)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re