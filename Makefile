# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 13:53:42 by djoly             #+#    #+#              #
#    Updated: 2018/01/26 10:24:19 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME	= libft_malloc_$(HOSTTYPE).so
FILES	= malloc.c \
				ft_header.c\
				ft_init.c\
				ft_putchar.c\
				ft_puthexa.c\
				ft_putnbr.c\
				ft_putstr.c\
				ft_strlen.c

SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
#INC		= -I include -I .
INC		= -I include -I .
LIB		= -L ft_printf -lftprintf
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
		#@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
		@echo "\033[91mCompiling \033[97m"
		@make -C ft_printf
		@$(CC) -shared -o $(NAME) $(OBJS) $(LIB)
		@ln -s $(NAME) libft_malloc.so
		@echo "\033[90mDone \033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92mDeleting\033[97m"
	@rm -rf .obj
	@echo "\033[96mClean done\033[97m"

fclean: clean
	@echo "\033[92mDeleting\033[97m"
	@rm -f $(NAME)
	@echo "\033[96mFclean Done\033[97m"
	@rm -f libft_malloc.so libft_malloc_x86_64_Darwin.so

re: fclean all

.PHONY: all clean fclean re
