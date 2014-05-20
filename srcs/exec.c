/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:59:54 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:35:16 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "ftsh.h"

int		ft_exec_one(t_tree *tree, t_env *e, int active_pipe)
{
	char	**cmd;
	int		child;

	if ((cmd = ft_check_builtin(tree->str)) != NULL)
	{
		tree->success = ft_exec_builtin(cmd, e);
		return (0);
	}
	if ((child = fork()) == 0)
	{
		if (active_pipe)
			ft_pipe_ch(1, e->pipes);
		if (!(cmd = ft_valid_cmd(e, tree->str)))
			_exit(1);
		execve(cmd[0], cmd, e->env);
		ft_cmd_not_found(cmd[0]);
		_exit(1);
	}
	else
		ft_wait_child(child, tree, e, active_pipe);
	return (0);
}

void	ft_exec_all(t_tree *tree, t_env *e)
{
	if (tree->left)
		ft_exec_all(tree->left, e);
	if (tree->root && IS_R_ARROWS(tree->root->str))
		ft_init_rarrows(tree, e);
	if (tree->root && !IS_L_ARROW(tree->root->str))
		ft_init_larrow(tree->root, e);
	if (tree->root && !IS_LL_ARROW(tree->root->str))
		ft_init_llarrow(tree->root);
	if (tree->root && !IS_PIPE(tree->root->str))
		pipe_token(tree, e);
	else if (ISN_TOK(tree->str))
		ft_exec_one(tree, e, 0);
	else if (!IS_AND(tree->str) || !IS_OR(tree->str))
		and_or_tokens(tree, e);
}

int		ft_exec(t_tree *tree, t_env *e)
{
	if (tree->left == NULL && tree->right == NULL)
		ft_exec_one(tree, e, 0);
	else
		ft_exec_all(tree, e);
	unlink("tmpfile");
	return (0);
}
