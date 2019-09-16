# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:16:29 by kibotrel          #+#    #+#              #
#    Updated: 2019/09/16 12:45:58 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME			= doom-nukem

# All the directories needed to know where files should be (Can be changed)

SDL_DIR			= $(abspath sdl)
LFT_DIR			= libft
SRCS_DIR		= srcs
OBJS_DIR		= objs
INCS_DIR		= incs libft/incs sdl/include
BUILD_DIR		= $(SDL_DIR)/build
OBJS_SUBDIRS	= core usage setup clean

# Source files (Can be changed)

LFT				= libft/libft.a
INCS			= incs/env.h incs/doom.h
SRCS			= core/main.c		core/hooks.c		\
														\
				  usage/usage.c							\
														\
				  setup/setup.c		setup/graphic.c		\
														\
				  clean/sdl.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I./$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

# How files should be compiled with set flags (Can be changed)

CC				= gcc
OBJS			= $(SRCS:.c=.o)
LIBS			= -L./$(LFT_DIR) -lft $(shell $(BUILD_DIR)/bin/sdl2-config --libs)
CFLAGS			= $(C_INCS) -Wall -Wextra -Werror -O3 -g

# Color codes

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

# Check if object directory exists, build libs and then the Project

all: $(C_SUBDIRS) $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR);								\
	$(SDL_DIR)/configure --prefix $(BUILD_DIR);		\
	make -j;										\
	make install

$(NAME): $(BUILD_DIR) $(LFT) $(OBJS_DIR) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library "libft"

$(LFT):
	@make -sC $(LFT_DIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@make -sC $(LFT_DIR) clean
	@if [ -f "$(BUILD_DIR)/Makefile" ]; then		\
		make -sC $(BUILD_DIR) clean;				\
	fi
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
