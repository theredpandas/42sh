/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_buffer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:18:58 by cnathana          #+#    #+#             */
/*   Updated: 2014/05/30 11:26:30 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_BUFFER_H
# define FTSH_BUFFER_H

# include <sys/ioctl.h>
# include <termios.h>
# include "ftsh.h"

# define RETURN 10
# define ESCAPE 27
# define LEFT 4479771
# define RIGHT 4414235
# define UP 4283163
# define DOWN 4348699
# define BACKSPACE 127
# define CTRLD 4

typedef struct			s_bufinfo
{
	char				*str;
	char				*c;
	int					pos;
	int					size;
	int					tcurs_posx;
	int					tcurs_posy;
	struct winsize		ws;
}						t_bufinfo;

int		alloc_bufinfo(t_bufinfo *buf);

int		is_arrowkey(t_bufinfo *buf);

void	add_char(t_bufinfo *buf);

void	delete_char(t_bufinfo *buf);

#endif /* !FTSH_BUFFER_H */
