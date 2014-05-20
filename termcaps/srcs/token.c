/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:58 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:01:00 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

static t_list	*ft_addtoken(t_list *list, char *str, int value)
{
	t_list		*tmp;
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->token = ft_strdup(str);
	new->value = value;
	new->next = NULL;
	if (list == NULL)
		return (new);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

static t_list	*ft_jointoken(t_list *list, char c)
{
	t_list		*tmp;
	char		*tmp2;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->token;
	tmp->token = ft_charjoin(tmp->token, c);
	free(tmp2);
	return (list);
}

static int		ft_istoken(char c)
{
	if (c == '&' || c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

t_list			*ft_gettoken(char *cmd)
{
	int		i;
	char	*tmp;
	t_list	*list;

	i = -1;
	tmp = ft_strdup("");
	list = NULL;
	while (cmd[++i])
	{
		if (ft_istoken(cmd[i]) || cmd[i] == ';')
		{
			if (ft_strncmp(tmp, "", 1) != 0)
				list = ft_addtoken(list, ft_strtrim(tmp), 0);
			list = ft_addtoken(list, ft_charjoin("", cmd[i]), 1);
			if (cmd[i] == cmd [i + 1] && ft_istoken(cmd[i]))
				list = ft_jointoken(list, cmd[++i]);
			tmp = ft_strdup("");
		}
		else
			tmp = ft_charjoin(tmp, cmd[i]);
	}
	if (ft_strncmp(tmp, "", 1) != 0)
		list = ft_addtoken(list, ft_strtrim(tmp), 0);
	return (list);
}
