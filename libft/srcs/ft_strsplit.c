/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:33 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:35 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_num_words(char *s, char c)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			++res;
		++i;
	}
	return (res);
}

static void	ft_splitstr(char **tab, char *s, char c, int i)
{
	int		n;
	int		len;

	n = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			++len;
			++i;
		}
		if (len > 0)
		{
			tab[n] = ft_strsub(s, i - len, len);
			++n;
			len = 0;
		}
		else
			++i;
	}
}

char		**ft_strsplit(char *s, char c)
{
	char	**tab;
	int		nb;

	if (!s)
		return (NULL);
	nb = (ft_num_words(s, c));
	if ((tab = (char **)malloc(sizeof(char *) * (nb + 1))) == NULL)
		return (NULL);
	ft_splitstr(tab, s, c, 0);
	tab[nb] = NULL;
	return (tab);
}
