# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 20:45:07 by gbelange          #+#    #+#              #
#    Updated: 2022/08/06 14:36:59 by jmorneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

				
NAME = fdf.a
LIBFT = libft.a
CC = @gcc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f
OBJS = $(SRC_FILES:.c=.o)
INCLUDE = -I include/

SRC_DIR = src/

.c.o:
	@echo "$(_BLUE)$(_BOLD)Compilation Printf: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#Couleurs!
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_WHITE=$'\x1b[37m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_IWHITE=$'\x1b[47m

SRC_FILES =	$(wildcard $(SRC_DIR)*.c)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) src/*.o

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)
	rm ./a.out
	
test :
		make all
		clear
		gcc -lmlx -framework OpenGL -framework AppKit fdf.a && ./a.out

re: fclean all