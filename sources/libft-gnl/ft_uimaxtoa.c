/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:33:37 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/23 16:33:39 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa(uintmax_t n)
{
	uintmax_t	num;
	size_t		size;
	char		*res;

	num = n;
	size = 0;
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	if (!(res = ft_strnew(size ? size : 1)))
		return (NULL);
	num = n;
	res[0] = '0';
	while (num != 0)
	{
		size--;
		res[size] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
