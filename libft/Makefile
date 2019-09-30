NAME = libft.a

LIBC_PATH = libc_functions/
ADD_PATH = additional_functions/
BONUS_PATH = bonus_functions/
EXTRA_PATH = extra_functions/
INCLUDE_PATH = includes/
OBJ_PATH = objects/

GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror -I $(INCLUDE_PATH) 

AR = ar
AR_FLAGS = rcs

LIBC_FUNCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c

ADD_FUNCS = ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c ft_strsplit.c ft_strsub.c ft_strtrim.c

BONUS_FUNCS = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c

EXTRA_FUNCS = ft_power.c ft_sqrt.c ft_fibonacci.c ft_isprime.c ft_find_next_prime.c ft_eof2eos.c

LIBC_FULL = $(addprefix $(LIBC_PATH), $(LIBC_FUNCS))
ADD_FULL = $(addprefix $(ADD_PATH), $(ADD_FUNCS))
BONUS_FULL = $(addprefix $(BONUS_PATH), $(BONUS_FUNCS))
EXTRA_FULL = $(addprefix $(EXTRA_PATH), $(EXTRA_FUNCS))

LIBC_OBJ = $(addprefix $(OBJ_PATH), $(LIBC_FUNCS:.c=.o))
ADD_OBJ = $(addprefix $(OBJ_PATH), $(ADD_FUNCS:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_PATH), $(BONUS_FUNCS:.c=.o))
EXTRA_OBJ = $(addprefix $(OBJ_PATH), $(EXTRA_FUNCS:.c=.o))

OBJECTS = $(LIBC_OBJ) $(ADD_OBJ) $(BONUS_OBJ) $(EXTRA_OBJ)

all: $(NAME)

$(NAME): $(OBJECTS)
		@($(AR) $(AR_FLAGS) $(NAME) $(OBJECTS))
		@(ranlib $(NAME))
		@(echo "\n"$(NAME) "was created!")

clean:
		@(/bin/rm -rf $(OBJ_PATH))
		@(echo "All object files have been deleted!")

fclean: clean
		@(/bin/rm -f $(NAME))
		@(echo $(NAME) "has been deleted!")


re: fclean all

objects:
		@(mkdir $(OBJ_PATH))

objects/%.o: $(LIBC_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -c $< -o $@)
		@(echo $< "->" $@)

objects/%.o: $(ADD_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -c $< -o $@)
		@(echo $< "->" $@)	

objects/%.o: $(BONUS_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -c $< -o $@)
		@(echo $< "->" $@)


objects/%.o: $(EXTRA_PATH)%.c | objects
		@($(GCC) $(GCC_FLAGS) -c $< -o $@)
		@(echo $< "->" $@)
