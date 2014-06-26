/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 10:59:31 by cnathana          #+#    #+#             */
/*   Updated: 2014/06/26 13:18:13 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftsh.h"
#include "libft.h"

void	ft_print_user(t_env *e)
{
	if (e->user)
	{
		ft_putstr("\033[36m");
		ft_putstr(e->user);
		ft_putstr("\033[0m - ");
	}
}

void	ft_print_prompt(t_env *e)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	ft_print_user(e);
	if (e->pwd && e->home)
	{
		len = ft_strlen(e->home);
		ft_putstr("\033[33m");
		if (!ft_strncmp(e->pwd, e->home, len))
		{
			tmp2 = ft_strsub(e->pwd, len, ft_strlen(e->pwd) - len);
			tmp = ft_strjoin("~", tmp2);
			ft_putstr(tmp);
			free(tmp);
			free(tmp2);
		}
		else
			ft_putstr(e->pwd);
		ft_putstr("\033[0m");
	}
	ft_putstr("\033[36m 42sh> ");
}
