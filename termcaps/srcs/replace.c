/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:44 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:46 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

char	*replace_tilde(char *cmd, t_env *e)
{
	char	*tmp;
	int		i;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '~')
		{
			tmp = ft_strsub(cmd, i + 1, ft_strlen(cmd) - i - 1);
			cmd = ft_strsub(cmd, 0, i);
			cmd = ft_strnjoin(2, cmd, e->home, tmp);
		}
	}
	return (cmd);
}

int		is_limit(char c)
{
	if (c == '|' || c == ' ' || c == '\t' || c == '\0' || c == ';'
			|| c == '&' || c == '>' || c == '<')
		return (1);
	return (0);
}

char	*replace(char *cmd, char *env, int i, int j)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(env, j - i, ft_strlen(env) - j + i);
	tmp2 = ft_strsub(cmd, j, ft_strlen(cmd) - j);
	cmd = ft_strsub(cmd, 0, i);
	cmd = ft_strnjoin(2, cmd, tmp, tmp2);
	return (cmd);
}

char	*replace_dollar(char *cmd, t_env *e)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '$' && !is_limit(cmd[i + 1]))
		{
			j = i + 1;
			while (!is_limit(cmd[++j]))
				;
			tmp = ft_strjoin(ft_strsub(cmd, i + 1, j - i - 1), "=");
			k = 0;
			while ((e->env)[k] && ft_strncmp((e->env)[k], tmp, j - i) != 0)
				k++;
			if ((e->env)[k] && ft_strncmp((e->env)[k], tmp, j - i) == 0)
				cmd = replace(cmd, (e->env)[k], i, j);
		}
	}
	return (cmd);
}
