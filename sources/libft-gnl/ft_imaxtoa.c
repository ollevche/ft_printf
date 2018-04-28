/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:33:02 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/23 16:33:05 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t n)
{
	intmax_t	num;
	size_t		size;
	char		*res;

	if (n == INTMAX_MIN)
		return (ft_strdup("-9223372036854775808"));
	num = n > 0 ? n : -n;
	size = n > 0 ? 0 : 1;
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	if (!(res = ft_strnew(size ? size : 1)))
		return (NULL);
	num = n > 0 ? n : -n;
	res[0] = n < 0 ? '-' : '0';
	while (num != 0)
	{
		size--;
		res[size] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}
