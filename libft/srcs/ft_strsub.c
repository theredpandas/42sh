/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:37 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:39 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char *s, int start, int len)
{
	char	*res;
	int		i;

	if (!s || (res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
