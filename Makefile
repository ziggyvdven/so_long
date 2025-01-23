# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 13:45:36 by zvandeven         #+#    #+#              #
#    Updated: 2024/08/15 14:14:59 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RT	= \033[0m
G	= \033[0;32m

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Program name
NAME 			= so_long
LIBMLX			= ./lib/MLX42

# Compiler and flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

# others
RM				= rm -f
MAKE			= make

# Objects 
OBJS_PATH		= objs/
OBJS			= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))
OBJS_BONUS		= $(addprefix $(OBJS_PATH), $(SRCS_BONUS_FILES:.c=.o))

# Sources
SRCS_PATH		= srcs/
BONUS_PATH		= srcs_bonus/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_BONUS		= $(addprefix $(SRCS_PATH), $(SRCS_BONUS_FILES))

# Includes
HEADERS			= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include

# library and source files
LIBFT			= ./libs/libft
LIBMLX  		= ./libs/MLX42
LIBS			= $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/homebrew/opt/glfw/lib/" -pthread -lm
SRCS_FILES		= so_long.c player.c init.c map_pars.c error.c map_checks.c fill_map.c load_png.c flood_fill.c moves.c\
				enemy.c animations.c enemy_moves.c\

					
#------------------------------------------------------------------------------#
#                                 RULES                                        #
#------------------------------------------------------------------------------#

all: libft libmlx $(NAME) 

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
        git -C ./libs clone https://github.com/codam-coding-college/MLX42.git; \
    fi
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \

$(NAME): $(OBJS_PATH) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(HEADERS)
		@echo "$(G)\n -- $(NAME) made 🐙 --$(RT)"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c 
	$(CC) $(CFLAGS) -o $@ -c $< 
	
$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	
libft:
	@echo "$(G)\n -- LOADING --$(RT)"
	@$(MAKE) -C $(LIBFT)

bonus: 
	@$(MAKE) "NAME=$(NAME_BONUS)" "OBJS=$(OBJS_BONUS)" "SRCS_FILES=$(SRCS_BONUS_FILES)" "SRCS_PATH=$(BONUS_PATH)"

clean:
	@rm -rf $(OBJS) $(OBJS_PATH)
	@$(MAKE) -C $(LIBFT) clean
	@rm -rf ./libs/MLX42
	@rm -rf $(LIBMLX)/build

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY:		all, clean, fclean, re, libmlx