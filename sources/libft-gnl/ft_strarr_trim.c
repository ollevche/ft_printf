/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:13:45 by ollevche          #+#    #+#             */
/*   Updated: 2018/03/22 13:13:45 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	indexes of arrays mean:
**	0 - length, 1 - width
*/

static char	**strarr_cpy(char **strarr, int begin[2], int end[2])
{
	char	**copy;
	int		i;

	copy = (char**)malloc(sizeof(char*) * (end[0] - begin[0] + 1));
	if (!copy)
		return (NULL);
	i = begin[0];
	while (i < end[0])
	{
		copy[i - begin[0]] = ft_strsub(strarr[i], begin[1], end[1] - begin[1]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	get_width_beg(char **strarr, char c)
{
	int	i;
	int	res;

	res = 0;
	while (strarr[0][res])
	{
		i = 0;
		while (strarr[i] && strarr[i][res] != c)
			i++;
		if (strarr[i])
			break ;
		res++;
	}
	return (res);
}

static int	get_width_end(char **strarr, char c, int width_beg)
{
	int	i;
	int	res;

	res = width_beg;
	while (strarr[0][res])
	{
		i = 0;
		while (strarr[i] && strarr[i][res] != c)
			i++;
		if (!strarr[i])
			break ;
		res++;
	}
	return (res);
}

char		**ft_strarr_trim(char **strarr, char c)
{
	int		begin[2];
	int		end[2];

	if (!strarr)
		return (NULL);
	begin[0] = 0;
	while (strarr[begin[0]] && !ft_strchr(strarr[begin[0]], c))
		begin[0]++;
	end[0] = begin[0];
	while (strarr[end[0]] && ft_strchr(strarr[end[0]], c))
		end[0]++;
	begin[1] = get_width_beg(strarr, c);
	end[1] = get_width_end(strarr, c, begin[1]);
	return (strarr_cpy(strarr, begin, end));
}
