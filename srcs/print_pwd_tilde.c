/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pwd_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:57:21 by cnathana          #+#    #+#             */
/*   Updated: 2014/06/26 13:57:46 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftsh.h"
#include "libft.h"

void	print_pwd_tilde(t_env *e, char *s)
{
	char	*tmp;
	char	*tmp2;
	int		len;

	len = ft_strlen(e->home);
	if (!ft_strncmp(e->home, s, len))
	{
		tmp2 = ft_strsub(s, len, ft_strlen(s) - len);
		tmp = ft_strjoin("~", tmp2);
		ft_putstr(tmp);
		free(tmp);
		free(tmp2);
	}
	else
		ft_putstr(s);
}
