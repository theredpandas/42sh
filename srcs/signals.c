/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:54 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/26 13:46:14 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ftsh.h"
#include "libft.h"

void	ft_signal_handle(int n)
{
	t_env	*e;

	if (n == SIGINT)
	{
		ft_putendl("\033[0m");
		e = singleton_env();
		ft_print_prompt(e);
	}
}

void	catch_signals(t_bufinfo *buf)
{
	signal(SIGINT, ft_signal_handle);
	signal(SIGTSTP, ft_signal_handle);
	signal(SIGQUIT, ft_signal_handle);
	ioctl(0, TIOCGWINSZ, &(buf->ws));
	signal(SIGWINCH, ft_signal_handle);
}
