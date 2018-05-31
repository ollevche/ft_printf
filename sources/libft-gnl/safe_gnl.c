/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:30:09 by ollevche          #+#    #+#             */
/*   Updated: 2018/04/03 12:30:10 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*safe_gnl(int fd)
{
	char	*line;
	int		ret_value;

	line = NULL;
	ret_value = get_next_line(fd, &line);
	if (ret_value < -1)
		ft_memdel((void**)&line);
	return (line);
}
