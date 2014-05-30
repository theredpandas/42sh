/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitchild.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:01:02 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/30 11:22:57 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "ftsh.h"

t_tree	*ft_lastcmd_access(t_tree *set)
{
	static t_tree	*mem = NULL;

	if (mem == NULL || set != NULL)
		mem = set;
	return (mem);
}

void	ft_active_pipe(t_tree *tree, t_env *e)
{
	ft_pipe_fath(0, e->pipes);
	if (tree->root->str[0] != '|')
	{
		if (tree->root->root->root && IS_R_ARROWS(tree->root->root->root->str))
			ft_init_rarrows(tree->root->root, e);
		ft_exec_one(tree->root->root->right, e, 0);
	}
	else
	{
		if (tree->root->root && IS_R_ARROWS(tree->root->root->str))
			ft_init_rarrows(tree->root, e);
		ft_exec_one(tree->root->right, e, 0);
	}
}

void	ft_wait_child(int child, t_tree *tree, t_env *e, int active_pipe)
{
	int		status;

	waitpid(child, &status, WUNTRACED);
	if (active_pipe)
		ft_active_pipe(tree, e);
	if (WIFEXITED(status))
		tree->success = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		ft_putstr("CTRL-C!\n");
		if (WTERMSIG(status) == SIGINT)
			tree->success = 1;
	}
	ft_lastcmd_access(tree);
}
