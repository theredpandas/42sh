/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:51:47 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/02 10:15:42 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 4096

# include <stdarg.h>

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

int					get_next_line(int const fd, char **line);
int					tputchar(int c);
int					ft_isspace(char c);
int					ft_putchar(char c);
int					ft_putstr(const char *s);
int					ft_strlen(const char *s);
int					ft_putendl(const char *s);
int					ft_putstr_fd(char const *s, int fd);
int					ft_putendl_fd(char const *s, int fd);
int					ft_strncmp(char *str1, char *str2, int len);

char				*ft_strdup(char *s);
char				*ft_strtrim(char *s);
char				*ft_charjoin(char *s, char c);
char				*ft_ichardelet(char *s, int i);
char				**ft_strsplit(char *s, char c);
char				*ft_strcat(char *dest, char *src);
char				*ft_icharjoin(char *s, char c, int i);
char				*ft_strsub(char *s, int start, int len);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(int n, const char *start, ...);

void				ft_bzero(char *s, int len);

#endif
