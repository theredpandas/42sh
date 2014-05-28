/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:33 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/28 10:46:54 by cnathana         ###   ########.fr       */
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
	t_bufinfo	*buf;
	char		*cmd;
	t_env		*e;
	t_tree		*tree;

	e = ft_getenv();
	buf = (t_bufinfo *)malloc(sizeof(t_bufinfo));
	catch_signals(buf);
	alloc_bufinfo(buf);
	if (buf != NULL){
	while (1)
	{
		cmd = ft_getcmd(buf, e);
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
		dup_reset(e);
	}
	ft_free_env(e);}
	return (0);
}
