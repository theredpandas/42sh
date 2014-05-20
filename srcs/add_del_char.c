/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_del_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:27:39 by cnathana          #+#    #+#             */
/*   Updated: 2014/03/12 13:18:49 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "ftsh.h"

void	delete_char(t_bufinfo *buf)
{
	buf->str = ft_ichardelet(buf->str, buf->pos);
	tputs(tgetstr("le", NULL), 1, tputchar);
	tputs(tgetstr("dc", NULL), 1, tputchar);
	--buf->size;
	--buf->pos;
	--buf->tcurs_posy;
}

void	add_char(t_bufinfo *buf)
{
	if (buf->c[0] >= ' ' && buf->c[0] <= '~' && buf->c[1] == 0)
	{
		buf->str = ft_icharjoin(buf->str, buf->c[0], buf->pos);
		ft_putchar(buf->c[0]);
		++buf->pos;
		++buf->size;
		++buf->tcurs_posy;
	}
}
