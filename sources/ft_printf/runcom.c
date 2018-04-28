/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:45:42 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/27 13:45:45 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

int			runcom(t_com *com, char **output)
{
	char	*obj;
	int		put;

	put = 0;
	obj = generate_obj(com);
	*output = generate_out(com, obj, &put);
	free(obj);
	return (put);
}

static char	*from_str(t_com *com)
{
	char	*obj;

	obj = NULL;
	if (com->spec == 'S')
		obj = as_wstr(com);
	else if (com->spec == 'C')
		obj = as_wchar(com);
	else if (com->spec == 's')
		obj = as_str(com);
	else if (com->spec == 'c')
		obj = as_char(com);
	return (obj);
}

char		*generate_obj(t_com *com)
{
	char	*obj;

	obj = NULL;
	if (com->spec && ft_strchr("sScC", com->spec))
		obj = from_str(com);
	else if (com->spec == 'p')
		obj = as_pointer(com);
	else if (com->spec == 'D' || com->spec == 'd' || com->spec == 'i')
		obj = as_int(com);
	else if (com->spec == 'U' || com->spec == 'u')
		obj = as_uint(com);
	else if (com->spec == 'O' || com->spec == 'o')
		obj = as_octal(com);
	else if (com->spec == 'X' || com->spec == 'x')
		obj = as_hex(com);
	else if (com->spec == 'b' || com->spec == 'B')
		obj = as_binary(com);
	else if (com->spec == 'n')
		obj = as_nspec(com);
	else if (com->spec == '%' || com->width > -1)
		obj = ft_strnewchr(1, com->spec);
	else
		obj = ft_strnew(0);
	return (obj);
}

static int	calc_size(t_com *com, char *obj, int *sign, int *objlen)
{
	int size;

	*objlen = ft_strlen(obj);
	if (!*objlen && (com->spec == 'c' || com->spec == 'C'))
		*objlen = 1;
	size = *objlen;
	if (obj[0] != '-' && (com->spec == 'i' ||
		com->spec == 'D' || com->spec == 'd'))
	{
		*sign = com->space_f ? ' ' : *sign;
		*sign = com->plus_f ? '+' : *sign;
	}
	if (*sign)
		size++;
	if (com->spec && com->width > size)
		size = com->width;
	return (size);
}

char		*generate_out(t_com *com, char *obj, int *size)
{
	char	*output;
	int		entry;
	int		i;
	int		sign;
	int		objlen;

	if (com->spec == 'n' || !obj)
		return (ft_strdup(obj));
	sign = 0;
	*size = calc_size(com, obj, &sign, &objlen);
	output = ft_strnewchr(*size, ' ');
	if (!output)
		return (NULL);
	entry = *size - objlen;
	if (com->minus_f)
		entry = sign ? 1 : 0;
	if (sign)
		output[entry - 1] = sign;
	i = 0;
	if (com->zero_f && !ft_strchr("pidDoOuUxXbB", com->spec))
		while (i < entry - (sign ? 1 : 0))
			output[i++] = '0';
	ft_memcpy(output + entry, obj, objlen);
	return (output);
}
