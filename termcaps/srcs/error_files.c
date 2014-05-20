/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:59:44 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:59:46 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"

void	ft_error_permission(char *str)
{
	ft_putstr("42sh: permission denied: ");
	ft_putendl(str);
}

void	ft_error_exist(char *str)
{
	ft_putstr("42sh: no such file or directory: ");
	ft_putendl(str);
}
