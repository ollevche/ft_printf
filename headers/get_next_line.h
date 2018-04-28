/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:37:36 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/12 13:16:01 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1024

typedef struct	s_file
{
	int					fd;
	char				*buf;
	struct s_file		*next;
}				t_file;

int				get_next_line(const int fd, char **line);
char			*safe_gnl(int fd);
int				skip_lines(int fd, int amount);

#endif
