/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:17:39 by cnathana          #+#    #+#             */
/*   Updated: 2014/05/20 17:22:51 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <term.h>
#include "ftsh.h"
#include "ftsh_buffer.h"
#include "ftsh_termcap.h"
#include "libft.h"

void	init_bufinfo(t_bufinfo *buf)
{
	ft_bzero(buf->c, 5);
	ft_bzero(buf->str, 2048);
	buf->pos = 0;
	buf->tcurs_posx = 0;
	buf->tcurs_posy = 0;
	buf->size = 0;
}

void	get_next_char(t_bufinfo *buf)
{
	if (is_arrowkey(buf))
		return ;
	else if (*(unsigned int *) buf->c == BACKSPACE)
	{
		if (buf->pos > 0)
			delete_char(buf);
	}
	else
	{
		if (buf->size < 2047)
			add_char(buf);
	}
}

char	*ft_getcmd(t_bufinfo *buf, t_env *e)
{
	ttermcap(1, e);
	init_bufinfo(buf);
	while (read(0, buf->c, 4))
	{
		if (*(unsigned int *) buf->c == RETURN)
			break ;
		get_next_char(buf);
		ft_bzero(buf->c, 4);
	}
	ttermcap(0, e);
	ft_putchar('\n');
	return (buf->str);
}
