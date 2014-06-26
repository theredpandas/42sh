/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:58:53 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/26 13:56:13 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftsh.h"

int		ft_error(char *cmd, char *s, char *cpl)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(s, 2);
	if (cpl)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(cpl, 2);
	}
	ft_putstr_fd("\n", 2);
	return (1);
}

char	*token_way(char *way, char *s)
{
	int		i;

	if (s[0] == '.' && s[1] == '.')
	{
		i = ft_strlen(way) - 1;
		while (i && way[i] != '/')
			i--;
		if (!i)
			return (ft_strdup("/"));
		return (ft_strsub(way, 0, i));
	}
	else if (s[0] == '.' && s[1] != '.')
		return (way);
	else
		return (ft_strnjoin(2, way, "/", s));
}

char	*make_way(t_env *e, char *arg)
{
	char	**args;
	char	*res;

	args = ft_strsplit(arg, '/');
	if (arg[0] == '/' && *args)
		res = ft_strjoin("/", *args++);
	else if (!(*args))
		return (ft_strdup("/"));
	else
		res = ft_strdup(e->pwd);
	while (*args)
		res = token_way(res, *args++);
	return (res);
}

int		ft_modif(t_env *env, char *way)
{
	char *tmp[3];

	tmp[0] = NULL;
	tmp[1] = ft_strdup("OLDPWD");
	tmp[2] = env->pwd;
	ft_setenv(env, tmp);
	tmp[1] = ft_strdup("PWD");
	tmp[2] = way;
	ft_setenv(env, tmp);
	return (0);
}

int		ft_cd(t_env *env, char **opt)
{
	char	*way;

	if (!(env->home) || !(env->pwd) || !(env->oldpwd))
		set_basicenv(env);
	if (!(opt[1]))
		way = env->home;
	else if (opt[1] && !(opt[2]))
	{
		if (ft_strncmp(opt[1], "-", 2) == 0)
		{
			print_pwd_tilde(env, env->oldpwd);
			ft_putchar('\n');
			way = env->oldpwd;
		}
		else
			way = make_way(env, opt[1]);
	}
	else
		return (ft_error("cd", "usage : cd [way or -]", NULL));
	if (way[0] == '/' && way [1] == '/')
		way++;
	if (chdir(way) < 0)
		return (ft_error("cd", "not a directory", opt[1]));
	else
		return (ft_modif(env, way));
}
