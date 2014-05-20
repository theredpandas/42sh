/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_icharjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:25 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:52:27 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_icharjoin(char *s, char c, int i)
{
	char	*res;
	int		j;

	if (!s || (res = (char *)malloc(sizeof(char) * 2048)) == NULL)
		return (NULL);
	j = -1;
	while (++j < i)
		res[j] = s[j];
	res[j++] = c;
	while (s[i] != 0)
		res[j++] = s[i++];
	free(s);
	ft_bzero(res + j, 2047 - j);
	return (res);
}
