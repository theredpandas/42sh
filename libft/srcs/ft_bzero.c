/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:52:01 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:52:03 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(char *s, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		s[i] = 0;
}
