/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:59:39 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/20 13:21:08 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftsh.h"
#include "libft.h"

int			error_unsetenv_arg(void)
{
	ft_putstr_fd("unsetenv: Too few arguments\n", 2);
	return (1);
}

int			ft_env(t_env *env, char **opt)
{
	int		i;

	if (!opt[1])
	{
		i = -1;
		while ((env->env)[++i])
			ft_putendl((env->env)[i]);
	}
	else
		ft_putendl("env: Too many arguments.");
	return (0);
}

int			ft_unsetenv(t_env *env, char **opt)
{
	int		i;

	if (!(*(++opt)))
		return (error_unsetenv_arg());
	while (*opt)
	{
		*opt = ft_strjoin(*opt, "=");
		ft_modif_env(env, *opt, NULL);
		i = 0;
		while ((env->env)[i]
				&& ft_strncmp(((env->env[i])), *opt, ft_strlen(*opt)) != 0)
			++i;
		if ((env->env)[i]
				&& ft_strncmp((env->env[i]), *opt, ft_strlen(*opt)) == 0)
		{
			while ((env->env)[i])
			{
				(env->env)[i] = (env->env)[i + 1];
				++i;
			}
		}
		opt++;
	}
	return (0);
}
