# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:16:29 by kibotrel          #+#    #+#              #
#    Updated: 2019/10/15 21:26:33 by kibotrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable / Library (Can be changed).

FT				= libft.a
SDL				= libsdl2.a
TTF				= libsdl2_ttf.a
BMP				= libbmp.a
NAME			= doom-nukem

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries (Can be changed).

LFT_DIR			= libft
LBMP_DIR		= libbmp
BREW_DIR		= $(HOME)/.brew
BREW_LIBS		= $(BREW_DIR)/lib

# Project (Can be changed).

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		:= incs
INCS_DIR		+= libft/incs
INCS_DIR		+= libbmp/incs
INCS_DIR		+= $(BREW_DIR)/include/SDL2

# All the subdirectories used in the project
# to organise source files (Can be changed).

OBJS_SUBDIRS	:= core
OBJS_SUBDIRS	+= game
OBJS_SUBDIRS	+= menu
OBJS_SUBDIRS	+= setup
OBJS_SUBDIRS	+= clean
OBJS_SUBDIRS	+= utils
OBJS_SUBDIRS	+= editor
OBJS_SUBDIRS	+= events

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project (Can be changed).

LFT				= $(LFT_DIR)/$(FT)
LBMP			= $(LBMP_DIR)/$(BMP)
LSDL			= $(BREW_LIBS)/$(SDL)
LTTF			= $(BREW_LIBS)/$(TTF)

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= incs/env.h
INCS			+= incs/core.h
INCS			+= incs/game.h
INCS			+= incs/menu.h
INCS			+= incs/clean.h
INCS			+= incs/enums.h
INCS			+= incs/setup.h
INCS			+= incs/utils.h
INCS			+= incs/editor.h
INCS			+= incs/events.h
INCS			+= incs/structs.h

# Source files (Can be changed)

SRCS			:= core/main.c
SRCS			+= core/game.c
SRCS			+= core/menu.c
SRCS			+= core/hooks.c
SRCS			+= core/editor.c
SRCS			+= core/selector.c
SRCS			+= core/settings.c
SRCS			+= game/camera.c
SRCS			+= game/movement.c
SRCS			+= game/keyboard.c
SRCS			+= menu/click.c
SRCS			+= menu/motion.c
SRCS			+= clean/env.c
SRCS			+= clean/sdl.c
SRCS			+= clean/ttf.c
SRCS			+= setup/setup.c
SRCS			+= setup/graphic.c
SRCS			+= utils/data.c
SRCS			+= utils/maths.c
SRCS			+= utils/usage.c
SRCS			+= utils/graphic.c
SRCS			+= editor/keyboard.c
SRCS			+= events/mouse.c
SRCS			+= events/motion.c
SRCS			+= events/keyboard.c

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CC				= gcc
OBJS			= $(SRCS:.c=.o)

# Linked libraries at compile time (Can be changed).

LIBS			:= -L$(LFT_DIR) -lft
LIBS			+= -L$(LBMP_DIR) -lbmp
LIBS			+= -L$(BREW_LIBS) -lSDL2
LIBS			+= -L$(BREW_LIBS) -lSDL2_ttf

# Compilation flags (Can be changed).

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror -O3

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(NAME)

$(NAME): $(LSDL) $(LTTF) $(LFT) $(LBMP) $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libraries installation using brew without prompting
# anything on standard output (Can be changed).

$(LSDL):
	@echo "$(GREEN)***   Installing library $(SDL)   ...  ***\n$(RESET)"
	@brew install sdl2 > /dev/null 2>&1

$(LTTF):
	@echo "$(GREEN)***   Installing library $(TTF)   ...  ***\n$(RESET)"
	@brew install sdl2_ttf > /dev/null 2>&1

# Libraries installion using their own Makefile (Can be changed).

$(LFT):
	@make -sC $(LFT_DIR) -j

$(LBMP):
	@make -sC $(LBMP_DIR) -j

# Rules used to create folders if they aren't already existing (Can be changed).

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files. (Can't be changed).

clean:
	@make -sC $(LFT_DIR) clean
	@make -sC $(LBMP_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting all executables and libraries after cleaning up
# all .o files (Can't be changed).

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@make -sC $(LBMP_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)
	@if [ -f "$(LSDL)" ]; then														\
		echo "$(GREEN)***   Deleting library $(SDL)   ...  ***\n$(RESET)";			\
		brew uninstall --ignore-dependencies sdl2 > /dev/null 2>&1;					\
	fi
	@if [ -f "$(LTTF)" ]; then														\
		echo "$(GREEN)***   Deleting library $(TTF)   ...  ***\n$(RESET)";			\
		brew uninstall sdl2_ttf > /dev/null 2>&1;									\
	fi

# Re-compile everything (Can't be changed).

re: fclean all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re
