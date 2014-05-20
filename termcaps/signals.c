/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 13:45:07 by cnathana          #+#    #+#             */
/*   Updated: 2014/03/12 11:26:13 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "ftsh.h"
#include "libft.h"
#include "ftsh_termcap.h"

void	ft_signal_handle(int n)
{
	if (n == SIGINT)
	{
		ttermcap(0, NULL);
		signal(SIGINT, SIG_DFL);
		exit(0);
	}
}

void	catch_signals(t_bufinfo *b)
{
	ioctl(0, TIOCGWINSZ, &(b->ws));
	signal(SIGINT, ft_signal_handle);
	signal(SIGWINCH, ft_signal_handle);
}
