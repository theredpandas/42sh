/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:16 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:18 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != 0)
	{
		str[i] = s1[i];
		++i;
	}
	while (s2 && s2[j] != 0)
	{
		str[i + j] = s2[j];
		++j;
	}
	str[i + j] = 0;
	return (str);
}
