/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:29 by fgrivill          #+#    #+#             */
/*   Updated: 2014/05/16 10:53:31 by fgrivill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

char	*ft_join(char *start, va_list ap, int n)
{
	char	*str;
	char	*res;

	res = NULL;
	while (n)
	{
		str = (char *)va_arg(ap, char *);
		if (str != NULL)
		{
			if (res == NULL)
				res = ft_strjoin(start, str);
			else
				res = ft_strjoin(res, str);
		}
		--n;
	}
	return (res);
}

char	*ft_strnjoin(int n, const char *start, ...)
{
	char	*str;
	va_list	ap;

	va_start(ap, start);
	str = ft_join((char *)start, ap, n);
	va_end(ap);
	return (str);
}
