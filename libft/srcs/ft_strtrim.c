/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:41 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/26 13:32:27 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char *s)
{
	char	*cpy;
	int		i;
	int		j;

	if (!s || (cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && ft_isspace(s[i]))
		++i;
	j = 0;
	while (s[i] != '\0')
		cpy[j++] = s[i++];
	--j;
	while (j && ft_isspace(cpy[j]))
		--j;
	cpy[j + 1] = '\0';
	return (cpy);
}
