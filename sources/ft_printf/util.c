/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:45:36 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/05 11:46:01 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

char	*extend_num(char *num, int prec)
{
	int		size;
	int		sign;
	char	*res;

	if (!num)
		return (NULL);
	if (*num == '0' && prec == 0)
		ft_strclr(num);
	size = ft_strlen(num);
	sign = (*num == '-') ? 1 : 0;
	if (!size || size >= prec + sign)
		return (num);
	res = ft_strnewchr(prec + sign, '0');
	if (!res)
		return (NULL);
	if (sign)
		res[0] = '-';
	ft_strcpy(res + (prec - size + sign * 2), num + sign);
	free(num);
	return (res);
}

char	*as_uiconverter(t_com *com, t_uiconvert convert, char llspec)
{
	uintmax_t	arg;
	char		*res;

	arg = va_arg(*com->ar, uintmax_t);
	res = NULL;
	if (com->spec == llspec || com->len == ll)
		res = convert((unsigned long long int)arg);
	else if (com->len == hh)
		res = convert((unsigned char)arg);
	else if (com->len == h)
		res = convert((unsigned short)arg);
	else if (com->len == l)
		res = convert((unsigned long int)arg);
	else if (com->len == j)
		res = convert((uintmax_t)arg);
	else if (com->len == z)
		res = convert((size_t)arg);
	else if (com->len == t)
		res = convert((ptrdiff_t)arg);
	else
		res = convert((unsigned int)arg);
	return (res);
}

char	*as_iconverter(t_com *com, t_iconvert convert, char llspec)
{
	intmax_t	arg;
	char		*res;

	arg = va_arg(*com->ar, intmax_t);
	res = NULL;
	if (com->spec == llspec || com->len == ll)
		res = convert((long long int)arg);
	else if (com->len == hh)
		res = convert((signed char)arg);
	else if (com->len == h)
		res = convert((short)arg);
	else if (com->len == l)
		res = convert((long int)arg);
	else if (com->len == j)
		res = convert((intmax_t)arg);
	else if (com->len == z)
		res = convert((size_t)arg);
	else if (com->len == t)
		res = convert((ptrdiff_t)arg);
	else
		res = convert((int)arg);
	return (res);
}

t_com	*new_com(va_list *ar, int *written)
{
	t_com *com;

	com = (t_com*)malloc(sizeof(t_com));
	if (!com)
		return (NULL);
	com->zero_f = 0;
	com->sharp_f = 0;
	com->space_f = 0;
	com->minus_f = 0;
	com->plus_f = 0;
	com->apost_f = 0;
	com->prec = -1;
	com->width = -1;
	com->len = nolen;
	com->spec = 0;
	com->ar = ar;
	com->written = written;
	return (com);
}

void	freecom(t_com **com)
{
	if (!com)
		return ;
	free(*com);
	*com = NULL;
}
