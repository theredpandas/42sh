/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:12 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:13 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*cpy;
	int		i;

	if ((cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		cpy[i] = s[i];
	cpy[i] = '\0';
	return (cpy);
}
