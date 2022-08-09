# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 15:53:17 by jmorneau          #+#    #+#              #
#    Updated: 2022/05/24 13:29:42 by jmorneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memcpy.c ft_toupper.c \
				ft_tolower.c ft_memset.c ft_calloc.c ft_strlen.c ft_strncmp.c ft_strmapi.c ft_strlen.c ft_substr.c ft_strdup.c ft_striteri.c \
				ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strtrim.c ft_split.c ft_strrchr.c \
				get_next_line.c get_next_line_utils.c \
				ft_printf_hex.c ft_printf_nbr.c ft_printf_ptr.c ft_printf_string.c ft_printf_unsigned.c ft_printf.c \
				free_table.c \
				

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
