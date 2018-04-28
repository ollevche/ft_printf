/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:29:49 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/21 17:29:51 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitobase(uintmax_t num, int base)
{
	uintmax_t	tmp;
	size_t		size;
	char		*res;

	tmp = num;
	size = 0;
	while (tmp)
	{
		tmp /= base;
		size++;
	}
	if (!size)
		return (ft_strdup("0"));
	res = ft_strnew(size);
	if (!res)
		return (NULL);
	while (num)
	{
		size--;
		res[size] = num % base + (num % base > 9 ? 'A' - 10 : '0');
		num /= base;
	}
	return (res);
}

char	*ft_tooctal(uintmax_t num)
{
	return (ft_uitobase(num, 8));
}

char	*ft_tohex(uintmax_t num)
{
	return (ft_uitobase(num, 16));
}

char	*ft_tobinary(uintmax_t num)
{
	return (ft_uitobase(num, 2));
}
