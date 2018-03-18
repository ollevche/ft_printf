/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:41:50 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/31 16:41:51 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TOOLS_H
# define FT_PRINTF_TOOLS_H

# include "../libft-gnl/headers/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>
# include <stddef.h>

typedef char* (*t_uiconvert)(uintmax_t);
typedef char* (*t_iconvert)(intmax_t);

typedef enum	e_lens
{
	nolen, hh, h, l, ll, j, t, z, L
}				t_lens;

typedef struct	s_com
{
	int		zero_f;
	int		sharp_f;
	int		space_f;
	int		minus_f;
	int		plus_f;
	int		apost_f;
	int		prec;
	int		width;
	t_lens	len;
	char	spec;
	va_list	*ar;
	int		*written;
}				t_com;

/*
**	ft_printf.c
*/

int				ft_printf(const char *format, ...);

/*
**	readcom.c
*/

int				readcom(const char *fot, t_com *com);

/*
**	runcom.c
*/

int				runcom(t_com *com, char **output);
char			*generate_obj(t_com *com);
char			*generate_out(t_com *com, char *obj, int *size);

/*
**	as_intnum_types.c
*/

char			*as_int(t_com *com);
char			*as_uint(t_com *com);
char			*as_octal(t_com *com);
char			*as_hex(t_com *com);

/*
**	as_str_types.c
*/

char			*as_str(t_com *com);
char			*as_char(t_com *com);
char			*as_wstr(t_com *com);
char			*as_wchar(t_com *com);

/*
**	as_extra_types.c
*/

char			*as_pointer(t_com *com);
char			*as_null(t_com *com);
char			*as_binary(t_com *com);
char			*as_nspec(t_com *com);

/*
**	util.c
*/

t_com			*new_com(va_list *ar, int *written);
void			freecom(t_com **com);
char			*extend_num(char *num, int prec);
char			*as_iconverter(t_com *com, t_iconvert convert, char llspec);
char			*as_uiconverter(t_com *com, t_uiconvert convert, char llspec);

#endif
