# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:16:29 by kibotrel          #+#    #+#              #
#    Updated: 2019/09/24 09:31:04 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME			= doom-nukem

# All the directories needed to know where files should be (Can be changed)

LZ_DIR			= $(LPNG_DIR)/ZLIB/lib
LFT_DIR			= libft
LPNG_DIR		= libpng
SRCS_DIR		= srcs
OBJS_DIR		= objs
BREW_DIR		= $(HOME)/.brew
INCS_DIR		= incs 							libft/incs						\
				  libpng/incs					$(BREW_DIR)/include/SDL2
BREW_LIBS		= $(BREW_DIR)/lib
OBJS_SUBDIRS	= core 		usage												\
				  setup		clean												\
				  menu		utils												\
				  events
#BUILD_TTF_DIR	= $(TTF_DIR)/build

# Source files (Can be changed)

LFT				= $(LFT_DIR)/libft.a
LPNG			= $(LPNG_DIR)/libpng.a
INCS			= incs/env.h incs/doom.h
SRCS			= core/main.c			core/hooks.c							\
				  core/selector.c												\
																				\
				  events/keyboard.c		events/mouse.c							\
																				\
				  usage/usage.c													\
																				\
				  setup/setup.c			setup/graphic.c							\
																				\
				  menu/menu.c			menu/editor.c							\
				  menu/game.c			menu/settings.c							\
																				\
				  clean/sdl.c													\
																				\
				  utils/graphic.c		utils/data.c							\
				  utils/maths.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

# How files should be compiled with set flags (Can be changed)

CC				= gcc
OBJS			= $(SRCS:.c=.o)
LIBS			= -L$(LFT_DIR) -lft -L$(LPNG_DIR) -lpng -L$(LZ_DIR) -lz -L$(BREW_LIBS) -lSDL2 -lSDL2_ttf
CFLAGS			= $(C_INCS) -Wall -Wextra -Werror -O3

# Color codes

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

# Check if object directory exists, build libs and then the Project

all: $(C_SUBDIRS) $(NAME)

$(NAME): $(LFT) $(LPNG) $(OBJS_DIR) $(C_OBJS)
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

# Compilation rules for libraries

$(LFT):
	@make -sC $(LFT_DIR) -j

$(LPNG):
	@make -sC $(LPNG_DIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@make -sC $(LFT_DIR) clean
	@make -sC $(LPNG_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@make -sC $(LPNG_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
