/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:36 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:38 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

t_tree		*ft_init_tree(t_list *token)
{
	t_tree		*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	new->str = ft_strdup(token->token);
	new->success = DIDN_EXE;
	new->left = NULL;
	new->right = NULL;
	new->root = NULL;
	return (new);
}

t_tree		*ft_push_token(t_tree *tree, t_list *token)
{
	t_tree		*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	new->str = ft_strdup(token->token);
	new->left = tree;
	new->right = NULL;
	new->root = NULL;
	tree->root = new;
	return (new);
}

t_tree		*ft_push_cmd(t_tree *tree, t_list *token)
{
	t_tree		*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	new->str = ft_strdup(token->token);
	new->right = NULL;
	if (ft_strncmp(tree->str, ";", 1) == 0)
	{
		new->left = tree;
		new->root = NULL;
		tree->root = new;
		return (new);
	}
	else
	{
		new->left = NULL;
		new->root = tree;
		tree->right = new;
		return (tree);
	}
}

t_tree		*ft_parse(char *cmd)
{
	t_list		*token;
	t_tree		*tree;

	token = ft_gettoken(cmd);
	if (ft_check_token(token))
		return (NULL);
	tree = ft_init_tree(token);
	token = token->next;
	while (token != NULL)
	{
		if (token->value == 1)
			tree = ft_push_token(tree, token);
		else
			tree = ft_push_cmd(tree, token);
		token = token->next;
	}
	return (tree);
}
