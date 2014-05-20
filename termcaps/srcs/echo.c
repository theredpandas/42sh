/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:59:32 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/20 13:21:10 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

int		ft_echo(t_env *e, char **opt)
{
	int		tmp;

	(void)e;
	tmp = 0;
	++opt;
	tmp = !ft_strncmp(*opt, "-n", 3) ? 1 : 0;
	if (tmp == 1)
		++opt;
	while (*opt)
	{
		ft_putstr(*opt++);
		if (*opt)
			ft_putchar(' ');
	}
	if (tmp)
		ft_putendl("\033[7m%\033[0m");
	else
		ft_putchar('\n');
	return (1);
}
