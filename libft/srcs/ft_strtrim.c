/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:41 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:42 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char *s)
{
	char	*cpy;
	int		i;

	if (!s || (cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = -1;
	while (ft_isspace(*s))
		s++;
	while (s[++i] != '\0')
		cpy[i] = s[i];
	--i;
	while (ft_isspace(cpy[i]))
		--i;
	cpy[i + 1] = '\0';
	return (cpy);
}
