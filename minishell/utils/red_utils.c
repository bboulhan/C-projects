/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:58:42 by aer-razk          #+#    #+#             */
/*   Updated: 2022/07/04 21:55:18 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	here_doc(char *arg, int *fd, int k, int i)
{
	char	*str;
	int		pid;

	str = ft_strdup("herdoc");
	fd[k] = open("/tmp/heredoc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	g_data.sig_q = 2;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		error_dup(fd, i);
		while (ft_strncmp(arg, str, ft_strlen(str)) != 0)
		{
			free(str);
			str = short_readline();
			if (str == NULL)
				exit(0);
			write_str(str, fd[k], arg);
		}
		exit(1);
	}
	here_doc2(pid, fd[k], str);
}

void	redirect_input(int *fd, int k, char **str, int j)
{
	char	*tmp;
	char	c[2];

	c[0] = '"';
	c[1] = 0;
	tmp = put_arg(str[j + 1]);
	fd[k] = open(tmp, O_RDWR, 0777);
	if (fd[k] == -1)
		error_dup(fd, check_redirection(str));
	else if (fd[k] != -1)
		dup2(fd[k], 0);
	close(fd[k]);
	free(tmp);
}

void	redirect_output(int i, int *fd, int k, char *arg)
{
	char	*tmp;
	char	c[2];

	c[0] = '"';
	c[1] = 0;
	tmp = put_arg(arg);
	if (i == 0)
		fd[k] = open(tmp, O_RDWR | O_CREAT | O_TRUNC, 0777);
	else if (i == 1)
		fd[k] = open(tmp, O_RDWR | O_CREAT | O_APPEND, 0777);
	dup2(fd[k], 1);
	close(fd[k]);
	free(tmp);
}

int	check_fd(int *fd, int k, char **str, int c)
{
	int	i;

	i = 0;
	while (i < k)
	{
		if (fd[i] == -1)
		{
			if (c == 0)
			{
				printf(CRED "do3afa2: %s:no such file or directory\n"
					RC, str[(i * 2) + 1]);
				g_data.exit_status = 1;
				free(fd);
			}
			return (0);
		}
		i++;
	}
	if (c == 0)
		free(fd);
	return (count_red(k, str));
}

int	simulate_redirection(t_list *node)
{
	int	i;
	int	j;
	int	*fd;
	int	k;

	j = 0;
	k = -1;
	i = check_redirection(node->red_args);
	fd = save_dup_malloc(i);
	if (i != 0)
	{
		while (++k < i)
		{
			j = check_redirection_index(node->red_args, j, k);
			if (check_fd(fd, i, node->red_args, 1) && ouble(node->red_args[j]))
				ouput_redirections(fd, j, node->red_args, k);
			else if (!ft_strncmp(node->red_args[j], "<", 1))
				redirect_input(fd, k, node->red_args, j);
			else if (!ft_strncmp(node->red_args[j], "<<", 2))
				here_doc(node->red_args[j + 1], fd, k, i);
		}
	}
	return (check_fd(fd, i, node->red_args, 0));
}
