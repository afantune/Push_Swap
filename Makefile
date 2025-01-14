# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afantune <afantune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 12:45:09 by afantune          #+#    #+#              #
#    Updated: 2025/01/07 14:30:20 by afantune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	Swap_rules.c Push_rules.c Rotate_rules.c Reverse_rules.c sorting.c \
	ft_lstlast.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c \
	ft_utils.c index.c ft_atoi.c check_args.c print_list.c threefourfivesort.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar
RM = @rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

OS = $(shell uname)

size ?= 10

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG = $(shell seq -1000 1000 | shuf -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l