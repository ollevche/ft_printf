/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_nfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ollevche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:16:08 by ollevche          #+#    #+#             */
/*   Updated: 2018/07/19 15:19:59 by ollevche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	frees some of the strings:
**	[n < 0 || n > 2] - none
**	[0] - first
**	[1] - second
**	[2] - both
*/

char	*ft_strjoin_nfree(char *s1, char *s2, int n)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	if (n == 0 || n == 2)
		free(s1);
	if (n == 1 || n == 2)
		free(s2);
	return (ret);
}
