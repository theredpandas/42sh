/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:04 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:05 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftsh.h"
#include <stdio.h>

void	ft_free_tree(t_tree *tree)
{
	if (tree->left != NULL)
		ft_free_tree(tree->left);
	if (tree->right != NULL)
		ft_free_tree(tree->right);
	free(tree);
	tree = NULL;
}

void	ft_free_env(t_env *env)
{
	int	i;

	i = -1;
	if (env->path)
	{
		while ((env->path)[++i])
			free((env->path)[i]);
		free(env->path);
	}
	free(env);
}
