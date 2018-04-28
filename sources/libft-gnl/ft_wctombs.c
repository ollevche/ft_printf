/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctombs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 20:44:10 by ollevche          #+#    #+#             */
/*   Updated: 2018/03/11 20:44:12 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_ind(wchar_t symbol)
{
	if (symbol <= (MB_CUR_MAX > 1 ? 127 : 255))
		return (0);
	if (symbol <= 2047)
		return (1);
	if (symbol <= 65535)
		return (2);
	return (3);
}

static char	*to_mbs(unsigned int symbol, char *res, int ind)
{
	if (ind + 1 > (int)MB_CUR_MAX)
	{
		free(res);
		return (NULL);
	}
	else if (ind == 1)
	{
		res[0] = (symbol >> 6) | 192;
		res[1] = ((symbol << 26) >> 26) | 128;
	}
	else if (ind == 2)
	{
		res[0] = (symbol >> 12) | 224;
		res[1] = ((symbol << 20) >> 26) | 128;
		res[2] = ((symbol << 26) >> 26) | 128;
	}
	else if (ind == 3)
	{
		res[0] = (symbol >> 18) | 240;
		res[1] = ((symbol << 14) >> 26) | 128;
		res[2] = ((symbol << 20) >> 26) | 128;
		res[3] = ((symbol << 26) >> 26) | 128;
	}
	return (res);
}

char		*ft_wctombs(wchar_t symbol)
{
	int		ind;
	char	*res;

	ind = calc_ind(symbol);
	if (!(res = ft_strnew(ind + 1)))
		return (NULL);
	if (ind == 0)
		res[0] = symbol;
	else
		res = to_mbs(symbol, res, ind);
	return (res);
}
