/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:26:54 by ollevche          #+#    #+#             */
/*   Updated: 2018/09/19 15:27:12 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_check_str(char *str, char *valid)
{
	if (!str)
		return (0);
	while (*str && ft_strrchr(valid, *str))
		str++;
	if (*str)
		return (0);
	return (1);
}
