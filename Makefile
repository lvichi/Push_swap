# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 19:57:48 by lvichi            #+#    #+#              #
#    Updated: 2024/02/25 14:11:44 by lvichi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
FILES = src/*.c
OBJS = obj/*.o
BONUS_FILES = src_bonus/*.c
BONUS_OBJS = obj_bonus/*.o

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(OBJS): $(FILES)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $(FILES)
	@mv *.o obj/

$(BONUS_OBJS): $(BONUS_FILES)
	@mkdir -p obj_bonus
	@$(CC) $(CFLAGS) -c $(BONUS_FILES)
	@mv *.o obj_bonus/

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) obj obj_bonus

fclean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(NAME) $(BONUS_NAME) obj obj_bonus

re: fclean all

bonus_re : fclean bonus
