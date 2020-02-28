# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindhol <mlindhol@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 07:51:49 by mlindhol          #+#    #+#              #
#    Updated: 2020/02/28 08:49:58 by mlindhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker
NAME_PS = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

HEADERS_DIRECTORY = ./includes/
HEADER_FILES = push_swap.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADER_FILES))

SOURCES_DIRECTORY = ./sources/
SOURCE_FILES =	display.c \
				exit.c \
				indexing.c \
				initialization.c \
				list_functions.c \
				median.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				sort.c \
				sort_algo.c \
				swap.c \
				utilities.c \
				validate.c 
SOURCE_FILES_CH = checker.c
SOURCE_FILES_PS = push_swap.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCE_FILES))
SOURCES_PS = $(addprefix $(SOURCES_DIRECTORY), $(SOURCE_FILES_PS))
SOURCES_CH = $(addprefix $(SOURCES_DIRECTORY), $(SOURCE_FILES_CH))

OBJECTS_DIRECTORY = ./objects/
OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))
OBJECT_FILES_CH = $(patsubst %.c, %.o, $(SOURCE_FILES_CH))
OBJECT_FILES_PS = $(patsubst %.c, %.o, $(SOURCE_FILES_PS))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES))
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES_PS))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_FILES_CH))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_PS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_PS) -o $(NAME_PS)
	@echo "\n$(NAME_PS): $(GREEN)$(NAME_PS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_PS) was created$(RESET)"

$(NAME_CH): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS) $(OBJECTS_CH)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) $(OBJECTS_CH) -o $(NAME_CH)
	@echo "\n$(NAME_PS): $(GREEN)$(NAME_CH) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GREEN)$(NAME_CH) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME_PS): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME_PS): $(GREEN)$(LIBFT) OK!$(RESET)"

lib:
	@echo "$(NAME_PS): $(GREEN)creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME_PS): $(GREEN)$(LIBFT) OK!$(RESET)"
run:
	$(CC) $(FLAGS) $(LIBRARIES) $(SOURCES_PS) $(SOURCES)
	./a.out 1 3 2

# ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; time ./push_swap $ARG | wc -l
# ./push_swap $ARG

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME_PS): [$(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)]"
	@echo "$(NAME_PS): [$(RED)object files were deleted$(RESET)]"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME_PS): [$(RED)$(LIBFT) was deleted$(RESET)]"
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS): [$(RED)$(NAME_PS) was deleted$(RESET)]"
	@rm -f $(NAME_CH)
	@echo "$(NAME_PS): [$(RED)$(NAME_CH) was deleted$(RESET)]"
	# @rm a.out

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re