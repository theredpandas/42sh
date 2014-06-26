/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:17:39 by cnathana          #+#    #+#             */
/*   Updated: 2014/06/26 12:59:07 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include "ftsh.h"
#include "ftsh_buffer.h"
#include "ftsh_termcap.h"
#include "libft.h"

void	init_bufinfo(t_bufinfo *buf, int prompt_size)
{
	ft_bzero(buf->c, 5);
	ft_bzero(buf->str, 2048);
	buf->pos = 0;
	buf->tcurs_posx = 0;
	buf->tcurs_posy = prompt_size;
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
	ft_print_prompt(e);
	ft_putstr("\033[32m");
	ttermcap(1, e);
	init_bufinfo(buf, e->prompt_size);
	while (read(0, buf->c, 4))
	{
		if (*(unsigned int *)buf->c == RETURN)
			break ;
		if (*(unsigned int *)buf->c == CTRLD)
		{
			ttermcap(0, e);
			return (NULL);
		}
		get_next_char(buf);
		ft_bzero(buf->c, 4);
	}
	ttermcap(0, e);
	ft_putstr("\033[0m\n");
	return (buf->str);
}
