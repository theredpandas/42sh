/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 10:21:28 by cnathana          #+#    #+#             */
/*   Updated: 2014/03/12 11:28:23 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <term.h>
#include <stdlib.h>
#include "ftsh.h"
#include "ftsh_termcap.h"

void	tenable(t_stermios *term, t_env *e)
{
	char	buff[2048];

	tgetent(buff, e->term);
	tcgetattr(0, term);
	term->c_lflag &= ~(ICANON | ECHO | ISIG | OPOST);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tputs(tgetstr("im", NULL), 1, tputchar);
	tcsetattr(0, TCSANOW, term);
}

void	tdisable(t_stermios *term)
{
	tputs(tgetstr("ei", NULL), 1, tputchar);
	term->c_lflag |= (ECHO | ICANON | ISIG | OPOST);
	tcsetattr(0, TCSANOW, term);
}

void	ttermcap(int n, t_env *e)
{
	static t_stermios	term;

	if (n)
		tenable(&term, e);
	else
		tdisable(&term);
}
