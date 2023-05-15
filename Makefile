# VARIABLE DECLARATION ############################################################################

NAME =			pipex

CC =			gcc

CFLAGS =		-Wall -Werror -Wextra

HEADERS =		./includes

BLACK	= 		\033[0;30m
RED		= 		\033[0;91m
GREEN	= 		\033[0;92m
YELLOW	= 		\033[0;93m
BLUE	= 		\033[0;94m
PURPLE	= 		\033[0;35m
CYAN	= 		\033[0;96m
WHITE	= 		\033[0;37m

SRCS =			srcs/pipex.c \
				srcs/process.c \
				srcs/get_path.c \
				srcs/pipex_utils.c \
				srcs/fd_management.c \

LIB = 			lib/libft.a \

LIBFT_PATH = 	./libft/
LIBFT_LIB = 	libft.a
MAKE_LIBFT = 	$(addprefix $(LIBFT_PATH), $(LIBFT_LIB))

OBJS =			$(SRCS:.c=.o)

# RULES ###########################################################################################

all: $(NAME)
$(NAME): $(OBJS)
	echo "$(CYAN)Compiling Pipex :$(WHITE)"
	$(shell cp libft/libft.a lib)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	echo "$(GREEN)Pipex successfully compiled ! \n\n$(WHITE)"

./srcs/%.o: ./srcs/%.c $(HEADERS)/pipex.h | libft make_lib
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@ 

clean:
	echo "$(YELLOW)Deleting all files exept 'all.a' and binaries$(WHITE)"
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_PATH)

fclean: clean
	echo "$(PURPLE)Deleting all files 'all.a' and binaries$(WHITE)"
	rm -rf $(NAME) $(NAME_BONUS) $(LIB) lib
	make fclean -C $(LIBFT_PATH)

make_lib:
	mkdir -p lib

re: fclean all

libft:
	make -C ./libft

.SILENT:

.PHONY: all clean fclean make_lib libft re

