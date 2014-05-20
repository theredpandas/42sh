/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:26 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:27 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *str1, char *str2, int len)
{
	int				i;
	int				res;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i < len && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == len)
		res = 0;
	else
		res = (s1[i] - s2[i]);
	return (res);
}
