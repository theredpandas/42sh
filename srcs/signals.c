/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:54 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/20 17:50:16 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ftsh.h"
#include "libft.h"

void	ft_signal_handle(int n)
{
	if (n == SIGINT)
	{
		ft_putchar(' ');
		return ;
	}
}

void	catch_signals(void)
{
//	signal(SIGINT, ft_signal_handle);
	signal(SIGTSTP, ft_signal_handle);
	signal(SIGQUIT, ft_signal_handle);
}
