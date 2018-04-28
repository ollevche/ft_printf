/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:21:43 by ollevche          #+#    #+#             */
/*   Updated: 2018/01/27 14:21:44 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_tools.h"

static int	print_fot(const char *fot, char **full_out, t_com *com)
{
	int	read;
	int	outlen;
	int	comlen;

	read = 0;
	comlen = 0;
	while (fot[read] && fot[read] != '%')
		read++;
	if (fot[read])
	{
		*(com->written) += read++;
		comlen = readcom(fot + read, com);
		outlen = runcom(com, full_out);
		if (*full_out == NULL)
			return ((*(com->written) = -1));
		write(1, fot, read - 1);
		write(1, *full_out, outlen);
		*(com->written) += outlen;
	}
	else
	{
		write(1, fot, read);
		*(com->written) += read;
	}
	return (read + comlen);
}

int			ft_printf(const char *fot, ...)
{
	va_list ar;
	t_com	*com;
	int		written;
	char	*full_out;

	if (!fot)
		return (0);
	va_start(ar, fot);
	written = 0;
	full_out = ft_strnew(1);
	while (full_out)
	{
		com = new_com(&ar, &written);
		if (!com)
			return (-1);
		ft_memdel((void **)&full_out);
		fot += print_fot(fot, &full_out, com);
		freecom(&com);
	}
	va_end(ar);
	return (written);
}
