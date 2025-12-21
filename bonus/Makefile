# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-asla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 18:21:00 by mel-asla          #+#    #+#              #
#    Updated: 2025/12/21 18:21:00 by mel-asla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS = checker.c \
	   ft_atol.c \
	   ft_check.c \
	   ft_input_pars.c \
	   ft_split.c \
	   ft_strlcpy.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstadd_back.c \
	   ft_lstlast.c \
	   ft_lstsize.c \
	   ft_lstclear.c \
	   ft_lstdelone.c \
	   ft_push.c \
	   ft_rotate.c \
	   ft_reverse_rotate.c \
	   ft_swap.c \
	   gnl/get_next_line.c \
	   gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
