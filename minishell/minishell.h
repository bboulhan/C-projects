/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:19:27 by bboulhan          #+#    #+#             */
/*   Updated: 2022/06/26 23:56:31 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_RESET "\x1b[0m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

// typedef struct s_red
// {
// 	char	**args;
// 	char	**red_args;
// 	char	*cmd;
// 	char	type;
// }	t_red;

extern char **environ;

typedef struct s_list
{
	char			**table;
	char			*str;
	char			*cmd;
	char			**red_args;
	char			**args;
	struct s_list	*next;
	//struct s_red	*red;
	
}	t_list;

typedef struct s_env
{
	char			**env;
	char			**export;
}	t_env;

//utils
char	*ft_strjoin(char const *s1, char *s2);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t num, size_t size);
void	*ft_free(char **c);
char	**ft_strdup_0(char **source);
int		ft_strlen_2(char **s);
char	**ft_split(char const *s, char c);
char	**ft_realloc(char **table, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strdup(const char *source);
void	ft_putstr_fd(char *s, int fd);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//lexer
char	*cut_string(char *str, int i0, int i1);
char	**lexer_space(char *line);
int		lexer(char *line, t_list *node);
int		quoted(char	*line, int i);
char	**lexer_pipe(char *line);
void	add_node(t_list **node);
char	**lexer_space(char *line);
int		lexer2(t_list *node, t_list *tmp, char **par);

//parcer
int		cmd_and_args(t_list *node);
char	*put_arg(char *str);
void	*ft_error(int Er, char **table, char *str);
int		parcer(t_list *node);
int		parcing(char *line, t_list *node);
int		check_dollar(char *str, int start, int end);
char	*get_env(char *str);
char	*add_char(char *str, char c);

//
char	*ft_strjoin1(char *s1, char *s2);
void	init_node(t_list *node);
char	*check_cmd(char *str);
void	checker(char *line, t_list **node);

//redirection
int		red_parcer(t_list *node);
int		check_red(char *str);
int		is_red(char c);
int		check_red(char *str);
char	*red_with_quote(char *str, int *i);
char    **split_with_red(char *str);
int		red_parcing(t_list *node);


int		check_table(char **table, char *arg);
//check for redirections
int check_redirection(char **table);
int check_redirection_index(char **table, int index);
int simulate_redirection(t_list *node);

int check_table(char **table, char *arg);
char	**ft_strdup_2(char **source);

//bultins
void	export(t_env *env, t_list *table);
void	echo(char **argv);
void    cd(t_env *env, t_list *table);
void	pwd();
void	ft_exit();
void	env(t_env *env);

char **ft_strdup_red(char **source);
#endif
