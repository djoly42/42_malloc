# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djoly <djoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 13:53:42 by djoly             #+#    #+#              #
#    Updated: 2018/02/22 13:54:09 by djoly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME	= libft_malloc_$(HOSTTYPE).so
FILES	= malloc.c \
				ft_header.c\
				ft_init.c\
				ft_memory.c\
				ft_print.c\
				show_alloc_mem.c

SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I ft_printf -I .
LIB		= -L ft_printf -lftprintf
FLAGS	= -Wall -Wextra -Werror
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\033[91mCompiling \033[97m"
		@make -C ft_printf
		@$(CC) -g -shared -o $(NAME) $(OBJS) $(LIB) $(FLAGS)
		@ln -sf $(NAME) libft_malloc.so
		@echo "\033[90mDone \033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC) $(FLAGS)

clean:
	@echo "\033[92mDeleting\033[97m"
	@rm -rf .obj
	@make clean -C ft_printf
	@echo "\033[96mClean done\033[97m"

fclean: clean
	@echo "\033[92mDeleting\033[97m"
	@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "\033[96mFclean Done\033[97m"
	@rm -f libft_malloc.so libft_malloc_x86_64_Darwin.so

re: fclean all

.PHONY: all clean fclean re
