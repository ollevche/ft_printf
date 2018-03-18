/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:47:51 by ollevche          #+#    #+#             */
/*   Updated: 2018/02/27 13:47:58 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

#define IS_SPEC(C) (C && ft_strchr("sSpdDioOuUxXcCn%bB", C) ? 1 : 0)
#define IS_FLAG(C) (C && ft_strchr("0+- #\'", C) ? 1 : 0)
#define IS_LEN(C) (C && ft_strchr("hljtzL", C) ? 1 : 0)

static int	get_prec(const char *fot, t_com *com)
{
	int read;

	read = 0;
	if (*fot != '.')
		return (read);
	read++;
	com->prec = 0;
	if (fot[1] == '*')
	{
		com->prec = va_arg(*com->ar, int);
		read++;
	}
	else
		while (ft_isdigit(fot[read]))
		{
			com->prec = com->prec * 10 + fot[read] - '0';
			read++;
		}
	return (read);
}

static int	get_width(const char *fot, t_com *com)
{
	int read;

	read = 0;
	if (*fot == '*')
	{
		com->width = va_arg(*com->ar, int);
		if (com->width < 0)
		{
			com->minus_f = 1;
			com->width *= -1;
		}
		read++;
	}
	else if (*fot >= '1' && *fot <= '9')
	{
		com->width = 0;
		while (ft_isdigit(fot[read]))
		{
			com->width = com->width * 10 + fot[read] - '0';
			read++;
		}
	}
	return (read);
}

static int	set_flag(const char *fot, t_com *com)
{
	if (!IS_FLAG(*fot))
		return (0);
	if (*fot == '0')
		com->zero_f = 1;
	else if (*fot == '#')
		com->sharp_f = 1;
	else if (*fot == ' ')
		com->space_f = 1;
	else if (*fot == '-')
		com->minus_f = 1;
	else if (*fot == '+')
		com->plus_f = 1;
	else if (*fot == '\'')
		com->apost_f = 1;
	return (1);
}

static int	get_len(const char *fot, t_com *com)
{
	t_lens len;

	if (!IS_LEN(*fot) || (len = 0))
		return (0);
	if (fot[0] == 'h' && fot[1] == 'h')
		len = hh;
	else if (*fot == 'h')
		len = h;
	else if (*fot == 'l')
		len = l;
	else if (fot[0] == 'l' && fot[1] == 'l')
		len = ll;
	else if (*fot == 'j')
		len = j;
	else if (*fot == 't')
		len = t;
	else if (*fot == 'z')
		len = z;
	else if (*fot == 'L')
		len = L;
	if (len > com->len)
		com->len = len;
	else if (len == h && com->len == h)
		com->len = hh;
	return (len == hh || len == ll ? 2 : 1);
}

int			readcom(const char *fot, t_com *com)
{
	int	read;
	int	got;

	read = 0;
	got = 1;
	while (got)
	{
		got = 0;
		if ((got = get_prec(fot + read, com)))
			read += got;
		else if ((got = get_width(fot + read, com)))
			read += got;
		else if ((got = set_flag(fot + read, com)))
			read += got;
		else if ((got = get_len(fot + read, com)))
			read += got;
	}
	if (IS_SPEC(fot[read]) || com->width > -1)
		com->spec = fot[read++];
	return (read);
}
