/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:33 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/02 10:08:41 by cnathana         ###   ########.fr       */
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

void	print_tree(t_tree *tree, int i)
{
	if (tree->left)
		print_tree(tree->left, 1);
	switch (i)
	{
		case 0:
			ft_putstr("start: ");
			break;
		case 1:
			ft_putstr("left: ");
			break;
		default:
			ft_putstr("right: ");
			break;
	}
	ft_putendl(tree->str);
	if (tree->right)
		print_tree(tree->right, 2);
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
		dup_reset(e, 0);
		if ((cmd = ft_getcmd(buf, e)) == NULL)
			break ;
		if (cmd[0] != 0)
		{
			if ((tree = ft_parse(cmd)) != NULL)
			{
				t_tree	*debug = tree;
				print_tree(debug, 0);
				debug = NULL;
				ft_exec(tree, e);
				ft_free_tree(tree);
			}
			else
				ft_putendl("42sh: parse error");
		}
		dup_reset(e, 1);
	}
	ft_free_env(e);}
	return (0);
}
