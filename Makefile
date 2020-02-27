# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:16:29 by kibotrel          #+#    #+#              #
#    Updated: 2020/02/27 19:17:18 by demonwaves       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Environment.

UNAME			= $(shell uname -s)

# Executable / Libraries.

FT				= libft.a
BMP				= libbmp.a
NAME			= doom-nukem

# Color codes.

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries.

LFT_DIR			= libft
LBMP_DIR		= libbmp

# I/O Compilation.

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Location of all header files used in the project.

INCS_DIR		:= incs
INCS_DIR		+= libft/incs
INCS_DIR		+= libbmp/incs

# All the subdirectories used in the project.

OBJS_SUBDIRS	:= hud
OBJS_SUBDIRS	+= core
OBJS_SUBDIRS	+= game
OBJS_SUBDIRS	+= menu
OBJS_SUBDIRS	+= setup
OBJS_SUBDIRS	+= clean
OBJS_SUBDIRS	+= parse
OBJS_SUBDIRS	+= utils
OBJS_SUBDIRS	+= editor
OBJS_SUBDIRS	+= events
OBJS_SUBDIRS	+= texture

#------------------------------------ FILES -----------------------------------#

# Every libraries needed to compile the project.

LAO				= $(LAO_DIR)/$(AO)
LFT				= $(LFT_DIR)/$(FT)
LBMP			= $(LBMP_DIR)/$(BMP)
LSDL			= $(LSDL_DIR)/$(SDL)
LSND			= $(LSND_DIR)/$(SND)
LTTF			= $(LTTF_DIR)/$(TTF)

# Used header at each compilation to check file integrity.

INCS			:= incs/env.h
INCS			+= incs/hud.h
INCS			+= incs/core.h
INCS			+= incs/game.h
INCS			+= incs/menu.h
INCS			+= incs/clean.h
INCS			+= incs/parse.h
INCS			+= incs/enums.h
INCS			+= incs/setup.h
INCS			+= incs/utils.h
INCS			+= incs/editor.h
INCS			+= incs/events.h
INCS			+= incs/structs.h
INCS			+= incs/editor.h
INCS			+= incs/texture.h

# Source files.

SRCS			:= hud/debug.c
SRCS			+= hud/purse.c
SRCS			+= hud/weapon.c
SRCS			+= hud/lifebar.c
SRCS			+= hud/crosshair.c
SRCS			+= core/main.c
SRCS			+= core/game.c
SRCS			+= core/menu.c
SRCS			+= core/hooks.c
SRCS			+= core/editor.c
SRCS			+= core/selector.c
SRCS			+= core/settings.c
SRCS			+= game/hud.c
SRCS			+= game/click.c
SRCS			+= game/camera.c
SRCS			+= game/engine.c
SRCS			+= game/effector.c
SRCS			+= game/reload.c
SRCS			+= game/physics.c
SRCS			+= game/movement.c
SRCS			+= game/keyboard.c
SRCS			+= menu/click.c
SRCS			+= menu/motion.c
SRCS			+= clean/env.c
SRCS			+= clean/sdl.c
SRCS			+= clean/ttf.c
SRCS			+= clean/engine.c
SRCS			+= parse/sector.c
SRCS			+= parse/main.c
SRCS			+= parse/tools.c
SRCS			+= parse/vertex.c
SRCS			+= parse/entity.c
SRCS			+= parse/total.c
SRCS			+= parse/player_blank.c
SRCS			+= setup/hud.c
SRCS			+= setup/game.c
SRCS			+= setup/setup.c
SRCS			+= setup/graphic.c
SRCS			+= utils/usage.c
SRCS			+= utils/data_0.c
SRCS			+= utils/data_1.c
SRCS			+= utils/data_2.c
SRCS			+= utils/data_3.c
SRCS			+= utils/data_4.c
SRCS			+= utils/data_5.c
SRCS			+= utils/engine.c
SRCS			+= utils/floats.c
SRCS			+= utils/maths_0.c
SRCS			+= utils/maths_1.c
SRCS			+= utils/ft_power.c
SRCS			+= utils/checks_00.c
SRCS			+= utils/checks_01.c
SRCS			+= utils/graphic_0.c
SRCS			+= utils/graphic_1.c
SRCS			+= utils/graphic_2.c
SRCS			+= utils/ft_strdel.c
SRCS			+= utils/ft_add_str.c
SRCS			+= utils/ft_mul_str.c
SRCS			+= utils/ft_realloc.c
SRCS			+= utils/ft_power_str.c
SRCS			+= utils/ft_strjoin_free.c
SRCS			+= utils/ft_str_binary_to_nb.c
SRCS			+= utils/ft_str_mantisse_to_nb.c
SRCS			+= editor/keyboard.c
SRCS			+= events/mouse.c
SRCS			+= events/motion.c
SRCS			+= events/keyboard.c
SRCS			+= texture/texture_tools.c
SRCS			+= editor/events.c
SRCS			+= editor/events_tools.c
SRCS			+= editor/setup.c
SRCS			+= editor/clean.c
SRCS			+= editor/delete.c
SRCS			+= editor/display.c
SRCS			+= editor/display_part2.c
SRCS			+= editor/display_utils.c
SRCS			+= editor/entity.c
SRCS			+= editor/entity_part2.c
SRCS			+= editor/edit_menu.c
SRCS			+= editor/edit_menu_utils.c
SRCS			+= editor/sec_edit_menu.c
SRCS			+= editor/sec_edit_menu_utils.c
SRCS			+= editor/picture.c
SRCS			+= editor/text.c
SRCS			+= editor/player.c
SRCS			+= editor/portal.c
SRCS			+= editor/portal_utils.c
SRCS			+= editor/map_creation.c
SRCS			+= editor/map_creation_part2.c
SRCS			+= editor/map_creation_utils.c
SRCS			+= editor/vertex.c
SRCS			+= editor/sector.c
SRCS			+= editor/sector_part2.c
SRCS			+= editor/sector_check.c
SRCS			+= editor/sector_utils.c
SRCS			+= texture/texture.c

#------------------------------ OPERATING SYSTEM ------------------------------#

# Some changes have to be done depending on which OS we are currently
# dealing with. Darwin is for macOS else would include at least Linux.

ifeq ($(UNAME), Darwin)
	AO			=
	SDL			= libsdl2.a
	SND			=
	TTF			= libsdl2_ttf.a
	LAO_DIR		=
	LSDL_DIR	= $(HOME)/.brew/Cellar/sdl2/2.0.10/lib
	LSND_DIR	=
	LTTF_DIR	= $(HOME)/.brew/Cellar/sdl2_ttf/2.0.15/lib
	INCS_DIR	+=
	INCS_DIR	+= $(HOME)/.brew/Cellar/sdl2/2.0.10/include/SDL2
	INCS_DIR	+=
	INCS_DIR	+= $(HOME)/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2
else
	TAR			= tar -xf
	CURL		= curl -L --output archive.tar
	L_LIBS		= /usr/local/lib
	L_INCS		= /usr/local/include
	URL_AO		= http://downloads.xiph.org/releases/ao/libao-1.2.0.tar.gz
	URL_SDL		= https://www.libsdl.org/release/SDL2-2.0.10.tar.gz
	URL_SND		= http://www.mega-nerd.com/libsndfile/files/libsndfile-1.0.28.tar.gz
	URL_TTF		= https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.15.tar.gz
	AO			= libao.so
	SDL			= libSDL2.a
	SND			= libsndfile.a
	TTF			= libSDL2_ttf.a
	SRCS_AO		= libao-1.2.0
	SRCS_SDL	= SDL2-2.0.10
	SRCS_SND	= libsndfile-1.0.28
	SRCS_TTF	= SDL2_ttf-2.0.15
	LAO_DIR		= $(L_LIBS)
	LSDL_DIR	= $(L_LIBS)
	LSND_DIR	= $(L_LIBS)
	LTTF_DIR	= $(L_LIBS)
	INCS_DIR	+= $(L_INCS)
	INCS_DIR	+= $(L_INCS)/ao
	INCS_DIR	+= $(L_INCS)/SDL2

endif

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job.

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= gcc
OBJS			= $(SRCS:.c=.o)

# Linked libraries at compile time.

LIBS			:= -L$(LSDL_DIR) -lSDL2
LIBS			+= -L$(LTTF_DIR) -lSDL2_ttf
LIBS			+= -L$(LBMP_DIR) -lbmp
LIBS			+= -L$(LFT_DIR) -lft
LIBS			+= -L$(LSND_DIR) -lsndfile
LIBS			+= -L$(LAO_DIR) -lao
LIBS			+= -lm
LIBS			+= -lpthread

# Compilation flags.

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror -O3

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule to prompt some informations.

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies to compile our project.

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(LSDL) $(LTTF) $(LSND) $(LAO) $(LFT) $(LBMP) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libraries installation using brew or curl without prompting anything
# on standard output.

$(LAO):
	@echo "$(GREEN)***   Installing library $(AO)   ...  ***\n$(RESET)"
	@if [ $(UNAME) = Darwin ]; then												\
		echo "Libao OSX Here";																\
	elif [ ! -d "$(SRCS_AO)" ]; then											\
		echo "$(GREEN)***   Curl sources   ...   ***\n$(RESET)";				\
		$(CURL) $(URL_AO) > /dev/null 2>&1;										\
		echo "$(GREEN)***   Unpacking sources   ...   ***\n$(RESET)";			\
		$(TAR) archive.tar;	$(RM) archive.tar;									\
		echo "$(GREEN)***   Configure library   ...   ***\n$(RESET)";			\
		cd $(SRCS_AO);	./configure > /dev/null 2>&1;							\
		echo "$(GREEN)***   Compile library   ...   ***\n$(RESET)";				\
		sudo make install -j > /dev/null 2>&1;									\
		echo "$(GREEN)***   $(AO) successfully compiled   ***\n$(RESET)";		\
	fi

$(LSDL):
	@echo "$(GREEN)***   Installing library $(SDL)   ...  ***\n$(RESET)"
	@if [ $(UNAME) = Darwin ]; then												\
		brew install sdl2 > /dev/null 2>&1;										\
	elif [ ! -d "$(SRCS_SDL)" ]; then											\
		sudo apt-get install curl -y > /dev/null 2>&1;							\
		echo "$(GREEN)***   Curl sources   ...   ***\n$(RESET)";				\
		$(CURL) $(URL_SDL) > /dev/null 2>&1;									\
		echo "$(GREEN)***   Unpacking sources   ...   ***\n$(RESET)";			\
		$(TAR) archive.tar;	$(RM) archive.tar;									\
		echo "$(GREEN)***   Configure library   ...   ***\n$(RESET)";			\
		cd $(SRCS_SDL);	./configure > /dev/null 2>&1;							\
		echo "$(GREEN)***   Compile library   ...   ***\n$(RESET)";				\
		sudo make install -j > /dev/null 2>&1;									\
		echo "$(GREEN)***   $(SDL) successfully compiled   ***\n$(RESET)";		\
	fi

$(LSND):
	@echo "$(GREEN)***   Installing library $(SND)   ...  ***\n$(RESET)"
	@if [ $(UNAME) = Darwin ]; then												\
		brew install autoconf autogen automake flac libogg libtool libvorbis	\
		libopus pkg-config > /dev/null 2>&1										\
		echo "Libsndfile OSX Here";												\
	elif [ ! -d "$(SRCS_SND)" ]; then											\
		sudo apt-get install autoconf autogen automake build-essential			\
		libasound2-dev libflac-dev libogg-dev libtool libvorbis-dev libopus-dev	\
		pkg-config python -y > /dev/null 2>&1;									\
		echo "$(GREEN)***   Curl sources   ...   ***\n$(RESET)";				\
		$(CURL) $(URL_SND) > /dev/null 2>&1;									\
		echo "$(GREEN)***   Unpacking sources   ...   ***\n$(RESET)";			\
		$(TAR) archive.tar; $(RM) archive.tar;									\
		cd $(SRCS_SND);	./configure > /dev/null 2>&1;							\
		echo "$(GREEN)***   Compile library   ...   ***\n$(RESET)";				\
		sudo make install -j > /dev/null 2>&1;									\
		echo "$(GREEN)***   $(SND) successfully compiled   ***\n$(RESET)";		\
	fi

$(LTTF):
	@echo "$(GREEN)***   Installing library $(TTF)   ...  ***\n$(RESET)"
	@if [ $(UNAME) = Darwin ]; then												\
		brew install sdl2_ttf > /dev/null 2>&1;									\
	elif [ ! -d "$(SRCS_TTF)" ]; then											\
		sudo apt-get install libfreetype6-dev -y > /dev/null 2>&1;				\
		echo "$(GREEN)***   Curl sources   ...   ***\n$(RESET)";				\
		$(CURL) $(URL_TTF) > /dev/null 2>&1;									\
		echo "$(GREEN)***   Unpacking sources   ...   ***\n$(RESET)";			\
		$(TAR) archive.tar; $(RM) archive.tar;									\
		echo "$(GREEN)***   Configure library   ...   ***\n$(RESET)";			\
		cd $(SRCS_TTF);	./configure > /dev/null 2>&1;							\
		echo "$(GREEN)***   Compile library   ...   ***\n$(RESET)";				\
		sudo make install -j > /dev/null 2>&1;									\
		echo "$(GREEN)***   $(TTF) successfully compiled   ***\n$(RESET)";		\
	fi

# Libraries installion using their own Makefile.

$(LFT):
	@make -sC $(LFT_DIR) -j

$(LBMP):
	@make -sC $(LBMP_DIR) -j

# Rules used to create folders if they aren't already existing.

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Deleting all .o files.

clean:
	@make -sC $(LFT_DIR) clean
	@make -sC $(LBMP_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting all executables and libraries after cleaning up all .o files.

fclean: clean
	echo $(RM)
	@make -sC $(LFT_DIR) fclean
	@make -sC $(LBMP_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)
# UNINSTALL AO LIB OSX HERE
	@if [ -f "$(LAO)" ]; then													\
		echo "$(GREEN)***   Deleting library $(AO)   ...  ***\n$(RESET)";		\
	fi
# UNINSTALL SNDFILE LIB OSX HERE
	@if [ -f "$(LSND)" ]; then													\
		echo "$(GREEN)***   Deleting library $(SND)   ...  ***\n$(RESET)";		\
	fi
	@if [ -f "$(LTTF)" ]; then													\
		echo "$(GREEN)***   Deleting library $(TTF)   ...  ***\n$(RESET)";		\
		if [ $(UNAME) = Darwin ]; then											\
			brew uninstall sdl2_ttf > /dev/null 2>&1;							\
		fi;																		\
	fi
	@if [ -f "$(LSDL)" ]; then													\
		echo "$(GREEN)***   Deleting library $(SDL)   ...  ***\n$(RESET)";		\
		if [ $(UNAME) = Darwin ]; then											\
			brew uninstall --ignore-dependencies sdl2 > /dev/null 2>&1;			\
		fi;																		\
	fi
	@if [ $(UNAME) = Linux ]; then												\
		if [ -d $(SRCS_AO) ]; then												\
			sudo rm -rf $(SRCS_AO);												\
		fi;																		\
		if [ -d $(SRCS_SDL) ]; then												\
			sudo rm -rf $(SRCS_SDL);											\
		fi;																		\
		if [ -d $(SRCS_SND) ]; then												\
			sudo rm -rf $(SRCS_SND);											\
		fi;																		\
		if [ -d $(SRCS_TTF) ]; then												\
			sudo rm -rf $(SRCS_TTF);											\
		fi;																		\
		if [ -f $(LAO) ]; then													\
			sudo $(RM) $(L_LIBS)/libao*;										\
			sudo rm -rf $(L_LIBS)/ao $(L_LIBS)/ckport $(L_INCS)/ao;				\
		fi;																		\
		if [ -f $(LSDL) ]; then													\
			sudo $(RM) $(L_LIBS)/libSDL2*;										\
			sudo rm -rf $(L_INCS)/SDL2;											\
		fi;																		\
		if [ -f $(LSND) ]; then													\
			sudo $(RM) $(L_LIBS)/libsndfile* $(L_INCS)/sndfile*;				\
		fi;																		\
		if [ -f $(LTTF) ]; then													\
			sudo $(RM) $(L_LIBS)/libSDL2*;										\
			sudo rm -rf $(L_INCS)/SDL2;											\
		fi;																		\
	fi

# Re-build libs.

re-libs: $(OBJS_DIR) $(C_SUBDIRS) $(C_OBJS)
	@make -sC $(LFT_DIR) re
	@make -sC $(LBMP_DIR) re
	@echo "$(YELLOW)      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Re-compile everything.

re: fclean all

# Avoid unexpected behaviour when regular files get the same name
# as the following variables.

.PHONY: all clean fclean re
