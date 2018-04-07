/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:33:17 by ollevche          #+#    #+#             */
/*   Updated: 2018/04/07 16:33:18 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	skip_lines(int fd, int amount)
{
	int		i;
	char	*line;

	i = 0;
	while (i < amount)
	{
		line = safe_gnl(fd);
		if (!line)
			return (-1);
		free(line);
		i++;
	}
	return (1);
}