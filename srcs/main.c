/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:33 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/26 14:04:55 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"

void	dup_reset(t_env *e, int i)
{
	if (i == 1)
	{
		close(0);
		dup(e->fd_cpy[0]);
		close(1);
		dup(e->fd_cpy[1]);
	}
	else
	{
		e->fd_cpy[0] = dup(0);
		e->fd_cpy[1] = dup(1);
	}
}

t_env	*singleton_env(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
		e = ft_getenv();
	set_basicenv(e);
	return (e);
}

int		ft_main_loop(t_bufinfo *buf, t_env *e)
{
	t_tree	*tree;
	char	*cmd;

	dup_reset(e, 0);
	if ((cmd = ft_getcmd(buf, e)) == NULL)
		return (-1);
	if (cmd[0] != 0)
	{
		if ((tree = ft_parse(cmd)) != NULL)
		{
			ft_exec(tree, e);
			ft_free_tree(tree);
		}
		else
			ft_putendl("42sh: parse error");
	}
	dup_reset(e, 1);
	return (0);
}

int		main(void)
{
	t_bufinfo	*buf;
	t_env		*e;

	e = singleton_env();
	buf = (t_bufinfo *)malloc(sizeof(t_bufinfo));
	catch_signals(buf);
	alloc_bufinfo(buf);
	if (buf != NULL)
	{
		while (1)
		{
			if (ft_main_loop(buf, e) == -1)
				break ;
		}
		ft_free_env(e);
	}
	return (0);
}
