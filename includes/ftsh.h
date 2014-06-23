/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrivill <fgrivill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 10:53:57 by fgrivill          #+#    #+#             */
/*   Updated: 2014/06/23 10:19:02 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H

# include "ftsh_buffer.h"
# include "libft.h"
# define IS_R_ARROW(x) (ft_strncmp((x), ">", 2))
# define IS_L_ARROW(x) (ft_strncmp((x), "<", 2))
# define IS_LL_ARROW(x) (ft_strncmp((x), "<<", 3))
# define IS_RR_ARROW(x) (ft_strncmp((x), ">>", 3))
# define IS_R_ARROWS(x) (!IS_R_ARROW(x) || !IS_RR_ARROW(x))
# define IS_L_ARROWS(x) (!IS_L_ARROW(x) || !IS_LL_ARROW(x))
# define IS_PIPE(x) (ft_strncmp((x), "|", 2))
# define IS_AND(x) (ft_strncmp((x), "&&", 3))
# define IS_OR(x) (ft_strncmp((x), "||", 3))
# define IS_S_COLON(x) (ft_strncmp((x), ";", 2))
# define SET_RIG (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# define O_MODES (O_RDWR | O_CREAT)
# define ISN_TOK_A(x) (IS_OR(x) && IS_AND(x) && IS_S_COLON(x))
# define ISN_TOK_B(x) (!IS_R_ARROWS(x) && IS_PIPE(x) && !IS_L_ARROWS(x))
# define ISN_TOK(x) (ISN_TOK_A(x) && ISN_TOK_B(x))
# define DIDN_EXE 1234567980
# define BUILT_LST ft_cd, ft_env, ft_setenv, ft_unsetenv, ft_exit, ft_echo

typedef struct		s_env
{
	char			**path;
	char			*home;
	char			*user;
	char			*term;
	char			*pwd;
	char			*oldpwd;
	char			**env;
	int				tmp_fd;
	int				fd_cpy[2];
	int				pipes[2];
}					t_env;

typedef struct		s_list
{
	char			*token;
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct		s_tree
{
	char			*str;
	int				success;
	int				p[2];
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_tree	*root;
}					t_tree;

void				catch_signals(t_bufinfo *buf);

void				and_or_tokens(t_tree *t, t_env *e);

char				*ft_getcmd(t_bufinfo *buf, t_env *e);

int					ft_check_token(t_list *check);

char				**ft_setpath(void);

void				set_basicenv(t_env *e);

void				ft_cmd_not_found(char *str);

void				ft_print_prompt(t_env *e);

t_env				*ft_getenv(void);

t_list				*ft_gettoken(char *cmd);

t_tree				*ft_parse(char *cmd);

char				**ft_valid_cmd(t_env *e, char *str);

void				ft_exec_all(t_tree *tree, t_env *e);

int					ft_exec_one(t_tree *tree, t_env *e, int active_pipe);

void				ft_wait_child(int child, t_tree *tree, t_env *e, int ac);

void				pipe_token(t_tree *tree, t_env *e);

int					ft_pipe_ch(int in, int p[]);

int					ft_pipe_fath(int out, int p[]);

void				ft_modif_env(t_env *env, char *s1, char *s2);

t_tree				*ft_lastcmd_access(t_tree *set);

char				*replace_tilde(char *cmd, t_env *e);

char				*replace_dollar(char *cmd, t_env *e);

void				ft_error_open(void);

void				ft_error_permission(char *str);

void				ft_error_exist(char *str);

int					is_limit(char c);

void				print_pwd_tilde(t_env *e, char *s);

/*
** builtins
*/

int					ft_echo(t_env *e, char **opt);

int					ft_exec(t_tree *tree, t_env *e);

int					ft_init_larrow(t_tree *tree, t_env *e);

int					ft_init_llarrow(t_tree *tree);

int					ft_init_rarrows(t_tree *tree, t_env *e);

int					ft_check_access(char *str);

int					ft_env(t_env *env, char **opt);

int					ft_setenv(t_env *env, char **opt);

int					ft_unsetenv(t_env *env, char **opt);

char				**ft_check_builtin(char *cmd);

int					ft_cd(t_env *e, char **opt);

int					ft_exec_builtin(char **cmd, t_env *e);

/*
** free
*/

void				ft_free_tree(t_tree *tree);

void				ft_free_env(t_env *env);

#endif
