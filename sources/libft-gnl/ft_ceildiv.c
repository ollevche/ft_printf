/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceildiv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:51:27 by ollevche          #+#    #+#             */
/*   Updated: 2018/06/08 16:51:27 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ceildiv(int a, int b)
{
	int	res;
	int	subres;

	res = a / b;
	subres = res * b;
	if (subres < a)
		res++;
	return (res);
}
