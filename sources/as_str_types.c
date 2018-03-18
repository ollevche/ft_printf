/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_str_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:15:09 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/27 12:15:11 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

char	*as_str(t_com *com)
{
	char	*arg;
	int		size;
	char	*res;

	if (com->len == l)
		return (as_wstr(com));
	arg = va_arg(*com->ar, char *);
	if (!arg)
		return (as_null(com));
	size = ft_strlen(arg);
	if (com->prec > -1 && size > com->prec)
		size = com->prec;
	res = ft_strndup(arg, size);
	return (res);
}

char	*as_char(t_com *com)
{
	char	*res;
	char	c;

	if (com->len == l)
		return (as_wchar(com));
	c = va_arg(*com->ar, int);
	res = ft_strnewchr(1, c);
	return (res);
}

char	*as_wstr(t_com *com)
{
	wchar_t	*wstr;
	int		s;
	char	*res;
	char	*tmp;

	wstr = va_arg(*com->ar, wchar_t*);
	if (!wstr)
		return (as_null(com));
	s = 0;
	res = ft_strnew(0);
	tmp = ft_strnew(0);
	while (wstr[s] && tmp)
	{
		tmp = ft_strjoinfree(tmp, ft_wctombs(wstr[s]));
		if (com->prec > -1 && (int)ft_strlen(tmp) > com->prec)
			break ;
		free(res);
		res = ft_strdup(tmp);
		s++;
	}
	free(tmp);
	return (res);
}

char	*as_wchar(t_com *com)
{
	wchar_t	wchar;
	char	*res;

	wchar = va_arg(*com->ar, wchar_t);
	res = ft_wctombs(wchar);
	return (res);
}
