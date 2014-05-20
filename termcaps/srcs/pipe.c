/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 11:00:40 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 11:00:42 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftsh.h"

int		ft_pipe_ch(int in, int p[])
{
	if (dup2(p[1], in) < 0)
	{
		write(2, "dup2-1 error\n", 13);
		return (1);
	}
	close(p[1]);
	close(p[0]);
	return (0);
}

int		ft_pipe_fath(int out, int p[])
{
	if (dup2(p[0], out) < 0)
	{
		write(2, "dup2-2 error\n", 13);
		return (1);
	}
	close(p[1]);
	close(p[0]);
	return (0);
}
