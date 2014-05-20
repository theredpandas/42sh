/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_larrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:08 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:09 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ftsh.h"

static int		ft_is_readable(char *str)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, R_OK) == 0)
			return (1);
		ft_error_permission(str);
		return (0);
	}
	ft_error_exist(str);
	return (-1);
}

int				ft_init_larrow(t_tree *tree, t_env *e)
{
	int		fd;
	int		n;

	if ((n = ft_is_readable(tree->right->str)) == 1)
	{
		if ((fd = open(tree->right->str, O_RDONLY)) < 0)
			return (-1);
		if (dup2(fd, 0) < 0)
			return (-2);
		e->tmp_fd = fd;
	}
	return (0);
}

int				get_new_input(char **str, char *stop, int len)
{
	char	new[2048];

	ft_bzero(new, 2048);
	ft_putstr("heredoc> ");
	read(0, new, 2047);
	if (ft_strncmp(new, stop, len) != 0)
		*str = ft_strcat(*str, new);
	else
		return (0);
	return (1);
}

int				ft_init_llarrow(t_tree *tree)
{
	char	*str;
	char	*stop;
	int		len;
	int		n;

	if ((str = (char *)malloc(sizeof(char) * 8192)) == NULL)
		return (-1);
	ft_bzero(str, 8192);
	stop = tree->right->str;
	len = ft_strlen(stop);
	n = 1;
	while (n != 0)
		n = get_new_input(&str, stop, len);
	n = open("tmpfile", O_MODES, SET_RIG);
	ft_putstr_fd(str, n);
	close(n);
	n = open("tmpfile", O_MODES, SET_RIG);
	dup2(n, 0);
	free(str);
	return (0);
}
