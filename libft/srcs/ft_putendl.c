/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:41 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:52:43 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putendl(const char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		;
	write(1, s, i);
	write(1, "\n", 1);
	return (i + 1);
}
