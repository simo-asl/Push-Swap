# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: symo <symo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 12:00:00 by mel-asla          #+#    #+#              #
#    Updated: 2026/01/04 06:39:34 by symo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

SRCS = src/main.c \
	   src/push_swap_sort.c \
	   src/quick_sort.c \
	   src/sorting.c \
	   src/utils.c \
	   src/utils2.c \
	   src/ft_atol.c \
	   src/ft_check.c \
	   src/ft_input_pars.c \
	   src/ft_split.c \
	   src/ft_strlcpy.c \
	   src/ft_lstnew.c \
	   src/ft_lstadd_front.c \
	   src/ft_lstadd_back.c \
	   src/ft_lstlast.c \
	   src/ft_lstsize.c \
	   src/ft_lstclear.c \
	   src/ft_lstdelone.c \
	   src/ft_push.c \
	   src/ft_rotate.c \
	   src/ft_reverse_rotate.c \
	   src/ft_swap.c

BONUS_SRCS = bonus/checker.c \
             bonus/gnl/get_next_line.c \
             bonus/gnl/get_next_line_utils.c \
             bonus/src/ft_atol.c \
             bonus/src/ft_check.c \
             bonus/src/ft_input_pars.c \
             bonus/src/ft_split.c \
             bonus/src/ft_strlcpy.c \
             bonus/src/ft_lstnew.c \
             bonus/src/ft_lstadd_front.c \
             bonus/src/ft_lstadd_back.c \
             bonus/src/ft_lstlast.c \
             bonus/src/ft_lstsize.c \
             bonus/src/ft_lstdelone.c \
             bonus/src/ft_lstclear.c \
             bonus/src/ft_push.c \
             bonus/src/ft_swap.c \
             bonus/src/ft_rotate.c \
             bonus/src/ft_reverse_rotate.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

DEPS = $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)
clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
