/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:50 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:51 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftsh.h"

void		ft_modif_env(t_env *env, char *s1, char *s2)
{
	if (ft_strncmp(s1, "PATH=", 5) == 0)
		env->path = ft_strsplit(s2, ':');
	else if (ft_strncmp(s1, "PWD=", 4) == 0)
		env->pwd = s2;
	else if (ft_strncmp(s1, "OLDPWD=", 7) == 0)
		env->oldpwd = s2;
	else if (ft_strncmp(s1, "USER=", 5) == 0)
		env->user = s2;
	else if (ft_strncmp(s1, "HOME=", 5) == 0)
		env->home = s2;
	else if (ft_strncmp(s1, "TERM=", 5) == 0)
		env->term = s2;
}

void		ft_modif_env2(t_env *env, char *s1, char *s2)
{
	int		i;

	i = 0;
	s1 = ft_strjoin(s1, "=");
	ft_modif_env(env, s1, s2);
	while ((env->env)[i]
			&& ft_strncmp(s1, (env->env)[i], ft_strlen(s1)) != 0)
		++i;
	if (!(env->env)[i])
		(env->env)[i + 1] = NULL;
	(env->env)[i] = ft_strjoin(s1, s2);
}

int			ft_setenv(t_env *env, char **opt)
{
	if (!opt[1])
		ft_env(env, opt);
	else if (opt[1] && opt[2])
		ft_modif_env2(env, opt[1], opt[2]);
	else if (opt[1] && !opt[2])
		ft_modif_env2(env, opt[1], "");
	return (0);
}
