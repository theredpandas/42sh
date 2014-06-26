/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:20:10 by cnathana          #+#    #+#             */
/*   Updated: 2014/06/26 14:05:43 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <stdlib.h>
#include "ftsh.h"
#include "ftsh_buffer.h"
#include "libft.h"

void	tcurs_pos_refresh(t_bufinfo *buf, int chx, int chy)
{
	if (chy > 1)
	{
		buf->tcurs_posy = chy;
		buf->tcurs_posx += chx;
		tputs(tgetstr("up", NULL), 1, tputchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, buf->ws.ws_col), 1, tputchar);
	}
	else if (chy == 0)
	{
		tputs(tgetstr("do", NULL), 1, tputchar);
		buf->tcurs_posx += 1;
		buf->tcurs_posy = 0;
	}
	else
	{
		if (chy == 1)
			tputs(tgetstr("nd", NULL), 1, tputchar);
		if (chy == -1)
			tputs(tgetstr("le", NULL), 1, tputchar);
		buf->tcurs_posx += chx;
		buf->tcurs_posy += chy;
	}
}

void	move_lr(t_bufinfo *buf, int lr)
{
	if (lr == 1)
	{
		if (buf->pos > 0)
		{
			if (buf->tcurs_posy == 0 && buf->tcurs_posx)
				tcurs_pos_refresh(buf, -1, buf->ws.ws_col);
			else
				tcurs_pos_refresh(buf, 0, -1);
			--(buf->pos);
		}
	}
	if (lr == 2)
	{
		if (buf->pos < buf->size)
		{
			if (buf->tcurs_posy == (buf->ws.ws_col))
				tcurs_pos_refresh(buf, 1, 0);
			else
			{
				tcurs_pos_refresh(buf, 0, 1);
			}
			++(buf->pos);
		}
	}
}

int		is_arrowkey(t_bufinfo *buf)
{
	if (*(unsigned int *)buf->c == LEFT)
		move_lr(buf, 1);
	else if (*(unsigned int *)buf->c == RIGHT)
		move_lr(buf, 2);
	else if (*(unsigned int *)buf->c == UP)
		;
	else if (*(unsigned int *)buf->c == DOWN)
		;
	else
		return (0);
	return (1);
}
