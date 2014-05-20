/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:58:49 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/20 13:21:11 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "stdlib.h"

int		ft_exit(t_env *e, char **cmd)
{
	if (cmd[1] && cmd[2])
		ft_putendl("exit: Expression Syntax.");
	else
	{
		ft_free_env(e);
		ft_putendl("exit");
		exit(0);
	}
	return (0);
}

int		ft_match_builtin(char *cmd, char **builtin)
{
	int		i;
	int		len;

	i = -1;
	while (builtin[++i])
	{
		len = ft_strlen(builtin[i]);
		if (!ft_strncmp(builtin[i], cmd, len))
		{
			if (is_limit(cmd[len]))
				return (i);
		}
	}
	return (-1);
}

char	**builtin_tab(void)
{
	static char	*res[] = {"cd", "env", "setenv", "unsetenv", "exit", "echo"};

	return (res);
}

char	**ft_check_builtin(char *cmd)
{
	char	**builtin;

	builtin = builtin_tab();
	if (ft_match_builtin(cmd, builtin) >= 0)
		return (ft_strsplit(cmd, ' '));
	return (NULL);
}

int		ft_exec_builtin(char **cmd, t_env *e)
{
	char		**builtin;
	int			i;
	static int	(*tab[])(t_env*, char**) = {BUILT_LST};

	builtin = builtin_tab();
	if ((i = ft_match_builtin(*cmd, builtin)) >= 0)
		return (tab[i](e, cmd));
	return (0);
}
