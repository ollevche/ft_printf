/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:16:37 by ollevche          #+#    #+#             */
/*   Updated: 2018/09/26 15:16:38 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_free(char *str)
{
	char	*trimmed;

	if (!str)
		return (NULL);
	trimmed = ft_strtrim(str);
	free(str);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
