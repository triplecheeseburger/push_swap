# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:37:01 by hakim             #+#    #+#              #
#    Updated: 2022/01/15 00:14:32 by hakim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS_NAME = checker
SRCS =	main.c \
        deque/deque_1.c \
        deque/deque_2.c \
        operation/swap_n_push.c \
        operation/rotate_n_reverse.c \
        parser/parse.c \
        parser/parsing_utils.c \
        utils/utils.c \
        utils/utils_2.c \
        utils/merge_sort.c \
        utils/lis.c \
        sorting/sort_shorts.c \
        sorting/push_swap.c \
        sorting/sort_utils.c \
        sorting/sort_gets.c \
        sorting/sort_big.c \
        sorting/sort_big_pos.c
BONUS_SRCS = deque/deque_2.c \
             deque/deque_1.c \
             parser/parse.c \
             parser/parsing_utils.c \
             utils/merge_sort.c \
             utils/utils.c \
             utils/utils_2.c \
             sorting/sort_gets.c \
             get_next_line/get_next_line.c \
             get_next_line/get_next_line_utils.c \
             checkerdir/checker.c \
             checkerdir/checker_oper_1.c \
             checkerdir/checker_oper_2.c
OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
HDR = ./includes

LIB_DIR = ./libft
LIB_NAME = ft
LIB = $(LIB_DIR)/lib$(LIB_NAME).a

INCLUDES = -I$(HDR) -I$(LIB_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):$(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) $(OBJS) -o $(NAME)

$(LIB):
	make -C $(LIB_DIR) bonus

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIB) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: fclean all clean re bonus
