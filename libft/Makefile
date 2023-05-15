# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 17:14:37 by tduprez           #+#    #+#              #
#    Updated: 2023/03/07 12:49:59 by tduprez          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BLACK	= 		\033[0;30m
RED		= 		\033[0;91m
GREEN	= 		\033[0;92m
YELLOW	= 		\033[0;93m
BLUE	= 		\033[0;94m
PURPLE	= 		\033[0;35m
CYAN	= 		\033[0;96m
WHITE	= 		\033[0;37m

######## LIBFT #################################################################
SRCS =	ft_atoi.c \
		ft_itoa.c \
		ft_split.c \
		ft_error.c \
		ft_bzero.c \
		ft_close.c \
		ft_memset.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_memcpy.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_substr.c \
		ft_perror.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_strtrim.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_strlcpy.c \
		ft_strrchr.c \
		ft_isprint.c \
		ft_strmapi.c \
		ft_isdigit.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_tolower.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_lstiter.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_toupper.c \
		ft_striteri.c \
		ft_lstclear.c \
		ft_putnbr_fd.c \
		free_pointer.c \
		ft_lstdelone.c \
		free_str_arr.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putchar_fd.c \
		get_next_line.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \

HEADER = ./include

OBJS = $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC = gcc

RM = rm -f

AR = ar rcs

%.o:	%.c $(HEADER)/libft.h
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@ 

all:	$(NAME)
$(NAME): $(OBJS)
	echo "$(CYAN)Compiling Libft :$(WHITE)"
	@$(AR) $(NAME) $(OBJS)
	echo "$(GREEN)Libft successfully compiled ! \n\n$(WHITE)"

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
