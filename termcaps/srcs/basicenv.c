/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:58:43 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:58:45 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ftsh.h"

char	**ft_setpath(void)
{
	char	**path;

	path = (char **)malloc(sizeof(char *) * 8);
	path[0] = ft_strdup("/usr/local/bin");
	path[1] = ft_strdup("/usr/bin");
	path[2] = ft_strdup("/bin");
	path[3] = ft_strdup("/usr/sbin");
	path[4] = ft_strdup("/sbin");
	path[5] = ft_strdup("/opt/X11/bin");
	path[6] = ft_strdup("/usr/texbin");
	path[7] = NULL;
	return (path);
}

char	**tab_env(char *name, char *arg)
{
	char	**res;

	res = malloc(sizeof(char *) * 3);
	res[0] = NULL;
	res[1] = name;
	res[2] = arg;
	return (res);
}

void	set_basicenv(t_env *e)
{
	char	*path_min;

	path_min = ft_strjoin("/usr/local/bin:/usr/bin:/bin:/usr/sbin:",
			"/sbin:/opt/X11/bin:/usr/texbin");
	if (!(e->path))
		ft_setenv(e, tab_env("PATH", path_min));
	if (!(e->pwd))
	{
		e->pwd = getcwd(e->pwd, sizeof(e->pwd));
		ft_setenv(e, tab_env("PWD", e->pwd));
	}
	if (!(e->oldpwd))
		ft_setenv(e, tab_env("OLDPWD", e->pwd));
	if (!(e->home))
		ft_setenv(e, tab_env("HOME", e->pwd));
	if (!(e->user))
		ft_setenv(e, tab_env("USER", "guest"));
	if (!e->term)
		ft_setenv(e, tab_env("TERM", "xterm-256color"));
}
