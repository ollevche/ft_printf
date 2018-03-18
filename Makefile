#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ollevche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/12 19:03:20 by ollevche          #+#    #+#              #
#    Updated: 2018/02/12 19:03:22 by ollevche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

FLAGS	=	-Wall -Werror -Wextra -I./headers

SRCDIR	=	./sources/

OBJDIR	=	./objects/

LIBDIR	=	./libft-gnl/

SRC		=	ft_printf.c readcom.c runcom.c util.c as_intnum_types.c \
			as_str_types.c as_extra_types.c

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB		=	libft.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	cp $(LIBDIR)$(LIB) ./$(NAME)
	ar rs $(NAME) $(OBJ)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	gcc -o $@ -c $< $(FLAGS)

$(LIBDIR)$(LIB):
	make -C $(LIBDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)
