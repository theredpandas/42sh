/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:58:57 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:58:59 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include <stdlib.h>

int		ft_check_token(t_list *token)
{
	int		i;

	i = 0;
	if (token == NULL)
		return (1);
	while (token != NULL)
	{
		if (token->value)
			return (1);
		while (token->token[i] && ft_isspace(token->token[i]))
			++i;
		if (!token->token[i])
			return (1);
		if (token->next != NULL && !token->next->value)
			return (1);
		token = token->next;
		if (token != NULL)
		{
			token = token->next;
			if (token == NULL)
				return (1);
		}
	}
	return (0);
}
