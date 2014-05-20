/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:59:57 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:59:59 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"

void	and_or_tokens(t_tree *tree, t_env *e)
{
	if (!IS_AND(tree->str))
	{
		if (tree->left->success == 0)
			ft_exec_one(tree->right, e, 0);
	}
	if (!IS_OR(tree->str))
	{
		if (tree->left->success != 0)
			ft_exec_one(tree->right, e, 0);
	}
}

void	pipe_token(t_tree *tree, t_env *e)
{
	if (pipe(e->pipes) < 0)
		write(2, "Pipe Fail\n", 10);
	if (ISN_TOK(tree->str))
		ft_exec_one(tree, e, 1);
	else
		ft_exec_one(tree->right, e, 1);
}
