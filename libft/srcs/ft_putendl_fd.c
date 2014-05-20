/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:45 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:52:48 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putendl_fd(const char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i++])
		;
	write(fd, s, i);
	write(fd, "\n", 1);
	return (i + 1);
}
