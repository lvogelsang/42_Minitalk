# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 09:21:56 by lvogelsa          #+#    #+#              #
#    Updated: 2022/11/24 10:20:41 by lvogelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f

SRCS = ft_atoi.c \ft_bzero.c \ft_calloc.c \ft_isalnum.c \ft_isalpha.c \
	ft_isascii.c \ft_isdigit.c \ft_isprint.c \ft_itoa.c \ft_memchr.c \
	ft_memcmp.c \ft_memcpy.c \ft_memmove.c \ft_memset.c \
	ft_putchar_fd.c \ft_putendl_fd.c \ft_putnbr_fd.c \ft_putstr_fd.c \
	ft_split.c \ft_strchr.c \ft_strdup.c \ft_striteri.c \ft_strjoin.c \
	ft_strlcat.c \ft_strlcpy.c \ft_strlen.c \ft_strmapi.c \
	ft_strncmp.c \ft_strnstr.c \ft_strrchr.c \ft_strtrim.c \
	ft_substr.c \ft_tolower.c \ft_toupper.c \ft_lstadd_back.c \
	ft_lstadd_front.c ft_lstclear.c \ft_lstdelone.c \ft_lstiter.c \
	ft_lstlast.c \ft_lstmap.c \ft_lstnew.c \ft_lstsize.c \ft_format.c \
	ft_format_default.c \ft_print_c_pct.c \ft_print_d_i.c \
	ft_print_d_i_2.c \ft_print_p.c \ft_print_s.c \ft_print_u.c \
	ft_print_u_2.c \ft_print_x.c \ft_print_x_2.c \ft_printf.c \
	ft_width_adjustment.c \get_next_line.c \get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean 
	$(RM) $(NAME)
re: fclean all
