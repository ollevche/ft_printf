/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_extra_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:43:06 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/27 13:43:08 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

char	*as_pointer(t_com *com)
{
	char	*res;
	char	*tmp;

	tmp = ft_tohex(va_arg(*com->ar, uintmax_t));
	if (com->prec > -1)
		tmp = extend_num(tmp, com->prec);
	else if (com->zero_f && !com->minus_f)
		tmp = extend_num(tmp, com->width - 2);
	tmp = ft_strtolow(tmp);
	res = ft_strjoin("0x", tmp);
	free(tmp);
	return (res);
}

char	*as_null(t_com *com)
{
	char	*res;
	char	*null_str;

	null_str = "(null)";
	if (com->prec > -1)
		res = ft_strndup(null_str, com->prec);
	else
		res = ft_strdup(null_str);
	return (res);
}

char	*as_binary(t_com *com)
{
	return (as_uiconverter(com, ft_tobinary, 'B'));
}

char	*as_nspec(t_com *com)
{
	intmax_t	*n;
	char		*res;

	n = va_arg(*com->ar, intmax_t*);
	*n = *(com->written);
	res = ft_strnew(0);
	return (res);
}
