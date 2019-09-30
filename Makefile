# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 11:37:17 by rhulk             #+#    #+#              #
#    Updated: 2019/09/15 11:49:40 by rhulk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = push_swap
CH_NAME = checker

GCC = gcc

GCC_FLAGS = -Wall -Wextra -Werror

OBJ_PATH = objects/

INCLUDES_INCLUDE = includes/

SOURCES_PATH = sources/

SOURCES_FILES = \
		additional_misc.c \
		ft_create_stack.c \
		ft_operations.c \
		ft_operations_implementation.c \
		get_next_line.c \
		misc.c \
		swap_push.c \
		validation_checker.c

LIBINC = -I libft/includes/libft.h -L./libft -lft

OBJ_SOURCES_CORE = $(addprefix $(OBJ_PATH), $(SOURCES_FILES:.c=.o))

OBJECTS = $(OBJ_SOURCES_CORE) 

all: $(PS_NAME) $(CH_NAME)

$(PS_NAME): $(OBJECTS)
		@($(GCC) $(GCC_FLAGS) $(OBJECTS) push_swap.c -o $(PS_NAME)  $(LIBINC))
		@(echo "[0;92m"$(PS_NAME) "was created![0;0m")

$(CH_NAME): $(OBJECTS)
		@($(GCC) $(GCC_FLAGS) $(OBJECTS) checker.c -o $(CH_NAME)  $(LIBINC))
		@(echo "[0;92m"$(CH_NAME) "was created![0;0m")

clean:
		@(/bin/rm -rf $(OBJ_PATH))
		@(echo "[0;91mAll object files have been deleted![0;0m")

fclean: clean
		@(/bin/rm -f $(CH_NAME) $(PS_NAME))
		@(echo "[0;91m"$(PS_NAME) "have been deleted![0;0m")
		@(echo "[0;91m"$(CH_NAME) "have been deleted![0;0m")

re: fclean all

objects:
		@(mkdir $(OBJ_PATH))

objects/%.o: $(SOURCES_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -I $(INCLUDES_INCLUDE) -c $< -o $@)
		@(echo "[0;93m"$< "->" $@"[0;0m")
