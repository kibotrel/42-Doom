
NAME		= doom

# All the directories needed to know where files should be (Can be changed)

LFT_DIR				= libft
SRCS_DIR			= srcs/
OBJS_DIR			= objs/
INCS_DIR			= ./incs/ ./libft/incs/
OBJS_SUBDIRS	= core


# Source files (Can be changed)

LFT			= ./libft/libft.a
INCS		= incs/env.h
SRCS		= core/main.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

C_OBJS			= $(addprefix $(OBJS_DIR), $(OBJS))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(OBJS_DIR)$(dir))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))

# How files should be compiled with set flags (Can be changed)

CC			= gcc
OBJS		= $(SRCS:.c=.o)
LIBS		= -L$(LFT_DIR) -lft
CFLAGS	= $(C_INCS) -Wall -Wextra -Werror -O3 -g

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW	= \033[33m

# Check if object directory exists, build libs and then the Project

all: $(C_SUBDIRS) $(NAME)

$(NAME): $(LFT) $(OBJS_DIR) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Redefinition of implicit compilation rule to prompt some colors and file names during the said compilation

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Compilation rule for function library "libft"

$(LFT):
	@make -sC $(LFT_DIR) -j

# Deleting all .o files and then the directory where they were located

clean:
	@make -sC $(LFT_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(C_OBJS)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
