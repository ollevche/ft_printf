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

OBJDIR	=	./objects/

PFDIR	=	./sources/ft_printf/

LIBDIR	=	./sources/libft-gnl/

PFSRC	=	ft_printf.c readcom.c runcom.c util.c as_intnum_types.c \
			as_str_types.c as_extra_types.c

LIBSRC	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_strlen.c \
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
			ft_free_strarr.c ft_strarr_trim.c safe_gnl.c skip_lines.c ft_ceildiv.c \
			ft_strjoin_nfree.c ft_byte_to_uint.c ft_isnumber.c ft_intset.c \
			ft_check_str.c ft_strtrim_free.c

PFOBJ	=	$(addprefix $(OBJDIR), $(PFSRC:.c=.o))

LIBOBJ	=	$(addprefix $(OBJDIR), $(LIBSRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBOBJ) $(PFOBJ)
	@echo "creating $(NAME)"
	@ar rcs $(NAME) $(PFOBJ) $(LIBOBJ)

$(OBJDIR):
	@mkdir $(OBJDIR)

$(LIBOBJ): $(OBJDIR)%.o : $(LIBDIR)%.c
	@echo "creating libft-gnl object files"
	@gcc -o $@ -c $< $(FLAGS)

$(PFOBJ): $(OBJDIR)%.o : $(PFDIR)%.c
	@echo "creating printf object files"
	@gcc -o $@ -c $< $(FLAGS)

clean:
	@echo "removing objects"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "removing $(NAME)"
	@rm -f $(NAME)

re: fclean $(NAME)
