/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:01:44 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/23 18:01:45 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewchr(size_t size, char c)
{
	char	*str;

	str = (char*)malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, c, size);
	str[size] = 0;
	return (str);
}
