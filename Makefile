# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 19:57:48 by lvichi            #+#    #+#              #
#    Updated: 2024/02/21 14:44:29 by lvichi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
#LIBFT = -L libft -lft
FILES = src/*.c
OBJS = obj/*.o
#BONUS_FILES = src_bonus/*_bonus.c
#BONUS_OBJS = obj_bonus/*_bonus.o

all: $(NAME)

#bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

#$(BONUS_NAME): $(BONUS_OBJS)
#	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MINILIBX) $(LIBFT) -o $(BONUS_NAME)

$(OBJS): $(FILES)
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $(FILES)
	@mv *.o obj/

#$(BONUS_OBJS): $(BONUS_FILES)
#	@make -C minilibx-linux -s
#	@make -C libft -s
#	@mkdir -p obj_bonus
#	@$(CC) $(CFLAGS) -c $(BONUS_FILES)
#	@mv *_bonus.o obj_bonus/

clean:
	@$(RM) $(OBJS) obj
#	@make clean -C libft -s

fclean:
	@$(RM) $(OBJS) $(NAME) obj

re: fclean all

#bonus_re : fclean bonus
