# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvogelsa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:07:14 by lvogelsa          #+#    #+#              #
#    Updated: 2023/01/19 11:12:35 by lvogelsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all
	
