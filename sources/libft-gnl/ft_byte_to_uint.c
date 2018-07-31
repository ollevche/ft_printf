/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byte_to_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:40:46 by ollevche          #+#    #+#             */
/*   Updated: 2018/07/31 15:40:47 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_byte_to_uint(unsigned char b1, unsigned char b2,
									unsigned char b3, unsigned char b4)
{
	unsigned int num;

	num = b1 << 24 | b2 << 16 | b3 << 8 | b4;
	return (num);
}
