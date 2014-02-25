#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cobrecht <cobrecht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 14:34:47 by cobrecht          #+#    #+#              #
#    Updated: 2014/02/25 10:01:48 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	libft.a

SRC = 	ft_putchar.c   ft_strncpy.c  ft_putchar_fd.c  ft_memccpy.c\
		ft_putstr.c    ft_memset.c   ft_strncmp.c     ft_memmove.c\
		ft_strlen.c    ft_bzero.c    ft_isalnum.c     ft_memchr.c\
		ft_putnbr.c    ft_toupper.c  ft_isdigit.c     ft_memcmp.c\
		ft_strdup.c    ft_tolower.c  ft_putstr_fd.c   ft_strrchr.c\
		ft_strcpy.c    ft_isprint.c  ft_putnbr_fd.c   ft_strstr.c\
		ft_atoi.c      ft_isascii.c  ft_putendl.c     ft_strnstr.c\
		ft_strcmp.c    ft_isalpha.c  ft_putendl_fd.c  ft_memalloc.c\
		ft_strclr.c    ft_strcat.c   ft_strncat.c     ft_memdel.c\
		ft_strlcat.c   ft_strchr.c   ft_memcpy.c      ft_strnew.c\
		ft_strdel.c    ft_strsplit.c\
		ft_striter.c   ft_itoa.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mkdir obj
	@mv $(OBJ) ./obj

%.o: %.c
	@gcc -c -Wall -Wextra -Werror $(SRC) -I.

clean:
	@rm -rf ./obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
