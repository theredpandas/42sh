/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 14:18:53 by cnathana          #+#    #+#             */
/*   Updated: 2014/05/20 15:35:45 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftsh.h"
#include "ftsh_buffer.h"

int		alloc_bufinfo(t_bufinfo *cmd)
{
	if ((cmd->str = (char *) malloc(sizeof(char) * 2049)) == NULL)
		return (-1);
	if ((cmd->c = (char *) malloc(sizeof(char) * 5)) == NULL)
		return (-1);
	return (0);
}
