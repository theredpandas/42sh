/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh_termcap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:59:20 by cnathana          #+#    #+#             */
/*   Updated: 2014/03/05 18:01:28 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_TERMCAP_H
# define FTSH_TERMCAP_H

# include <termios.h>
# include "ftsh.h"

typedef struct termios	t_stermios;

void	ttermcap(int n, t_env *e);

#endif /* !FTSH_TERMCAP_H */
