/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:18 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:35:13 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"
#include "libft.h"

void			ft_cmd_not_found(char *str)
{
	ft_putstr("42sh: ");
	ft_putstr(str);
	ft_putendl(": command not found");
}

int				ft_check_access(char *str)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, X_OK) == -1 || access(str, R_OK) == -1)
		{
			ft_error_permission(str);
			return (-2);
		}
		else
			return (0);
	}
	return (-1);
}

char			*ft_search_path(char *str, char **path)
{
	int		i;
	int		n;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strnjoin(2, path[i], "/", str);
		if ((n = ft_check_access(tmp)) == 0)
		{
			free(str);
			return (tmp);
		}
		else if (n == -2)
			break ;
		free(tmp);
		++i;
	}
	if (n != -2)
		ft_cmd_not_found(str);
	return (NULL);
}

char			**ft_valid_cmd(t_env *e, char *str)
{
	char	**cmd;
	int		n;

	if (e->path == NULL)
		set_basicenv(e);
	cmd = ft_strsplit(str, ' ');
	if (str[0] == '/' || (str[0] == '.' && str[1] == '/'))
	{
		if ((n = ft_check_access(cmd[0])) == 0)
			return (cmd);
		if (n == -1)
			ft_cmd_not_found(cmd[0]);
		return (NULL);
	}
	else
	{
		if (!(cmd[0] = ft_search_path(cmd[0], e->path)))
			return (NULL);
	}
	return (cmd);
}
