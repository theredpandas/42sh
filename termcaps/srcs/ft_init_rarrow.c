/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rarrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:12 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:13 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ftsh.h"

static int		ft_is_writable(char *str)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, R_OK) == 0 && access(str, W_OK) == 0)
			return (0);
		else
			return (-1);
	}
	return (1);
}

static int		ft_init_redir_r(t_tree *root, t_env *e)
{
	int		n;
	int		fd;

	if ((n = ft_is_writable(root->right->str)) == -1)
	{
		ft_error_permission(root->right->str);
		return (-1);
	}
	if ((fd = open(root->right->str, O_MODES | O_TRUNC, SET_RIG)) < 0)
		return (-2);
	e->tmp_fd = fd;
	if (dup2(fd, 1) < 0)
		return (-3);
	return (0);
}

static int		ft_init_redir_rr(t_tree *root, t_env *e)
{
	int		n;
	int		fd;

	if ((n = ft_is_writable(root->right->str)) == -1)
	{
		ft_error_permission(root->right->str);
		return (-1);
	}
	if ((fd = open(root->right->str, O_MODES | O_APPEND, SET_RIG)) < 0)
		return (-2);
	e->tmp_fd = fd;
	if (dup2(fd, 1) < 0)
		return (-3);
	return (0);
}

int				ft_init_rarrows(t_tree *tree, t_env *e)
{
	int		n;

	dup2(e->fd_cpy[1], 1);
	if (!IS_R_ARROW(tree->root->str))
	{
		if ((n = ft_init_redir_r(tree->root, e)) == -2 || n == -3)
		{
			ft_putendl("42sh: error while processing your command");
			return (-1);
		}
		else if (n == -1)
			return (-1);
	}
	else
	{
		if ((n = ft_init_redir_rr(tree->root, e)) == -2 || n == -3)
		{
			ft_putendl("42sh: error while processing your command");
			return (-1);
		}
		else if (n == -1)
			return (-1);
	}
	return (0);
}
