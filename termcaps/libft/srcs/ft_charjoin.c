/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:10 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:52:13 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_charjoin(char *s, char c)
{
	char	*res;
	int		len;

	len = ft_strlen(s) + 2;
	if ((res = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	res = ft_strcpy(res, s);
	res[len - 2] = c;
	res[len - 1] = '\0';
	return (res);
}
