#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ollevche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/18 17:11:38 by ollevche          #+#    #+#              #
#    Updated: 2018/03/18 12:30:16 by ollevche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a

FLAGS	=	-Wall -Werror -Wextra -I./headers

SRCDIR	=	./sources/

OBJDIR	=	./objects/

SRC		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlen.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcpy.c ft_strdup.c \
			ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_strncpy.c ft_isascii.c ft_memalloc.c ft_memdel.c \
			ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
			ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
			ft_putchar_fd.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_lstnew.c ft_lstdelone.c \
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_displaylist.c \
			ft_putstrarr.c ft_strsort.c ft_wordcount.c ft_strjoinfree.c \
			ft_imaxtoa.c ft_uimaxtoa.c ft_strtolow.c ft_uitobase.c \
			ft_strnewchr.c ft_strndup.c ft_wctombs.c get_next_line.c \
			ft_free_strarr.c ft_strarr_trim.c

OBJ 	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@echo "creating libft.a"
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@echo "creating libft object files"
	@gcc -o $@ -c $< $(FLAGS)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@echo "removing libft object files"
	@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	@echo "removing libft.a"
	@rm -rf $(NAME)

re: fclean all
