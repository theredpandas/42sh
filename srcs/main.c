/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:33 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/20 15:51:12 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"

void	dup_reset(t_env *e)
{
	dup2(e->fd_cpy[0], 0);
	dup2(e->fd_cpy[1], 1);
}

int		main(void)
{
	t_bufinfo	*cmd;
	t_env		*e;
	t_tree		*tree;

	e = ft_getenv();
	cmd = NULL;
	catch_signals();
	alloc_bufinfo(cmd);
	while (1)
	{
		ft_getcmd(cmd, e);
		if (cmd->str[0] != 0)
		{
			if ((tree = ft_parse(cmd->str)) != NULL)
			{
				ft_exec(tree, e);
				ft_free_tree(tree);
			}
			else
				ft_putendl("42sh: parse error");
		}
		dup_reset(e);
	}
	ft_free_env(e);
	return (0);
}
