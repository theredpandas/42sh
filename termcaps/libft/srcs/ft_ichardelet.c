/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ichardelet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:21 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:52:23 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_ichardelet(char *s, int i)
{
	char	*res;
	int		j;

	if (!s || (res = (char *)malloc(sizeof(char) * 2048)) == NULL)
		return (NULL);
	j = -1;
	while (++j < i - 1)
		res[j] = s[j];
	while (s[i] != 0)
		res[j++] = s[i++];
	free(s);
	ft_bzero(res + j, 2047 - j);
	return (res);
}
