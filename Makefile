# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 01:17:32 by motaouss          #+#    #+#              #
#    Updated: 2021/09/03 01:17:34 by motaouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CCFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_split.c ft_calloc.c ft_strjoin.c utils.c ft_getenv.c ft_exec.c
OBJ=$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all