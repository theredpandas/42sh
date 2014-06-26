/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:25 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/26 13:00:14 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"

void			set_env(t_env *e, char *env)
{
	if (ft_strncmp(env, "PATH=", 5) == 0)
		e->path = ft_strsplit(env + 5, ':');
	else if (ft_strncmp(env, "HOME=", 5) == 0)
		e->home = ft_strsub(env, 5, (ft_strlen(env) - 5));
	else if (ft_strncmp(env, "USER=", 5) == 0)
		e->user = ft_strsub(env, 5, (ft_strlen(env) - 5));
	else if (ft_strncmp(env, "TERM=", 5) == 0)
		e->term = ft_strsub(env, 5, (ft_strlen(env) - 5));
	else if (ft_strncmp(env, "PWD=", 4) == 0)
		e->pwd = ft_strsub(env, 4, (ft_strlen(env) - 4));
	else if (ft_strncmp(env, "OLDPWD=", 7) == 0)
		e->oldpwd = ft_strsub(env, 7, (ft_strlen(env) - 7));
}

static t_env	*ft_checkenv(t_env *e)
{
	if (!(e->path) || !(e->pwd) || !(e->oldpwd) || !(e->home) || !(e->user)
			|| !(e->term))
	{
		set_basicenv(e);
		if (e->path == NULL)
			e->path = ft_setpath();
		if (e->oldpwd == NULL)
			e->oldpwd = ft_strdup(e->pwd);
		if (e->home == NULL)
			e->home = ft_strdup(e->pwd);
		if (e->user == NULL)
			e->user = ft_strdup("guest");
		if (e->term == NULL)
			e->term = ft_strdup("xterm-256color");
	}
	return (e);
}

static t_env	*ft_initenv(t_env *e)
{
	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	e->env = NULL;
	e->path = NULL;
	e->home = NULL;
	e->user = NULL;
	e->term = NULL;
	e->pwd = NULL;
	e->oldpwd = NULL;
	e->prompt_size = 3;
	return (e);
}

static void		ft_welcome(void)
{
	ft_putendl("\033[36m");
	ft_putendl("              .,-:;vv;:=,");
	ft_putendl("            :H@@@MM@M#Hv.,+%;,");
	ft_putendl("       ,vX+ +M@@M@MM%=,-%HMMM@Xv,");
	ft_putendl("     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-");
	ft_putendl("    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@v.");
	ft_putendl("  ,%MM@@MH ,@%=             .---=-=:=,.");
	ft_putendl("  =@#@@@MX.,                -%HX$$%%%:;");
	ft_putendl(" =-.v@M@M$                   .;@MMMM@MM:");
	ft_putendl(" X@v -$MMv      \033[0;33mwelcome\033[36m       . +MM@@@M$");
	ft_putendl(",@M@H: :@:         \033[0;33mto         .\033[36m =X#@@@@-");
	ft_putendl(",@@@MMX, .        \033[0;33m42sh        vH-\033[36m ;@M@M=");
	ft_putendl(".H@@@@M@+,                    \033[0;33m%MM+.\033[36m.%#$.");
	ft_putendl(" vMMMM@MMHv.                  \033[0;33mXM@MH;\033[36m =;");
	ft_putendl("  v%+%$XHH@$=              , \033[0;33m.H@@@@MX,\033[36m");
	ft_putendl("  .=--------.           -%H.\033[0;33m,@@@@@MX,\033[36m");
	ft_putendl("  .%MM@@@HHHXX$$$%+- .:$MMX \033[0;33m=M@@MM%.\033[36m");
	ft_putendl("    =XMMM@MM@MM#H;,-+HMM@M+ \033[0;33mvMMMX=\033[36m");
	ft_putendl("      =%@M@M#@$-.=$@MM@@@M; \033[0;33m%M%=\033[36m");
	ft_putendl("        ,:+$+-,vH#MMMMMMM@= \033[0;33m=,\033[36m");
	ft_putendl("              =++%%%%+v:-.");
	ft_putendl("\033[0;0m");
	ft_putendl("\n\033[36mCURRENTLY IN DEV. To deactivate termcaps if there's a crash, just \"exit\" the shell!\033[0;0m\n");
}

t_env			*ft_getenv(void)
{
	t_env		*e;
	extern char	**environ;
	int			i;

	ft_welcome();
	e = NULL;
	e = ft_initenv(e);
	e->env = environ;
	i = -1;
	while (environ[++i] != NULL)
		set_env(e, environ[i]);
	e = ft_checkenv(e);
	return (e);
}
