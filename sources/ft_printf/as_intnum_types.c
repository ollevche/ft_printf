/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_num_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:14:47 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/27 12:14:53 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

static char	*group_num(char *num)
{
	char	sep;
	char	*grouped;
	int		n;
	int		gr_len;
	int		g;

	sep = *(localeconv()->thousands_sep);
	if (!num || !sep)
		return (num);
	n = ft_strlen(num);
	gr_len = n + n / 3 - (n % 3 ? 0 : 1);
	grouped = ft_strnewchr(gr_len, sep);
	if (!grouped)
		return (NULL);
	g = gr_len;
	while (g > -1)
	{
		g--;
		if ((gr_len - g) % 4 == 0)
			continue ;
		n--;
		grouped[g] = num[n];
	}
	free(num);
	return (grouped);
}

char		*as_octal(t_com *com)
{
	char	*res;
	char	*tmp;

	res = as_uiconverter(com, ft_tooctal, 'O');
	if (com->apost_f)
		res = group_num(res);
	if (com->prec > -1)
		res = extend_num(res, com->prec);
	if (!res)
		return (NULL);
	if (com->sharp_f && res[0] != '0')
	{
		tmp = res;
		res = ft_strjoin("0", tmp);
		free(tmp);
	}
	if (com->zero_f && !com->minus_f && com->prec < 0 && com->width > -1)
		res = extend_num(res, com->width);
	return (res);
}

char		*as_hex(t_com *com)
{
	char	*res;
	char	*tmp;
	int		sharp;

	res = as_uiconverter(com, ft_tohex, 0);
	if (!res || !res[0])
		return (res);
	sharp = com->sharp_f && (res[0] != '0') ? 2 : 0;
	if (com->prec > -1)
		res = extend_num(res, com->prec);
	if (com->zero_f && com->prec < 0 && !com->minus_f && com->width > -1)
		res = extend_num(res, com->width - sharp);
	if (sharp)
	{
		tmp = res;
		res = ft_strjoin("0X", tmp);
		free(tmp);
	}
	if (com->spec == 'x')
		res = ft_strtolow(res);
	return (res);
}

char		*as_uint(t_com *com)
{
	char	*res;

	res = as_uiconverter(com, ft_uimaxtoa, 'U');
	if (com->apost_f)
		res = group_num(res);
	if (com->prec > -1)
		res = extend_num(res, com->prec);
	if (com->zero_f && !com->minus_f && com->prec < 0 && com->width > -1)
		res = extend_num(res, com->width);
	return (res);
}

char		*as_int(t_com *com)
{
	char	*res;
	int		size;

	res = as_iconverter(com, ft_imaxtoa, 'D');
	if (com->apost_f)
		res = group_num(res);
	if (com->prec > -1)
		res = extend_num(res, com->prec);
	if (!res)
		return (NULL);
	if (com->zero_f && !com->minus_f && com->prec < 0 && com->width > -1)
	{
		size = com->width;
		if (res[0] == '-' || com->space_f || com->plus_f)
			size--;
		res = extend_num(res, size);
	}
	return (res);
}
