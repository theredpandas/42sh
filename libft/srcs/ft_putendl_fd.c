/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:41 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/02 10:15:30 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putendl_fd(const char *s, int fd)
{
	int		i;

	i = -1;
	while (s[++i])
		;
	write(fd, s, i);
	write(fd, "\n", 1);
	return (i + 1);
}
