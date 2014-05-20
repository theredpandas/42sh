/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:59:48 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:59:49 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftsh.h"

void	ft_error_open(void)
{
	ft_putstr("Failed to open file");
	_exit(1);
}
