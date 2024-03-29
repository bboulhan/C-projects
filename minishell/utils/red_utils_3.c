/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:58:10 by aer-razk          #+#    #+#             */
/*   Updated: 2022/07/04 10:05:38 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_str(char *str, int fd, char *arg)
{
	if (ft_strncmp(arg, str, ft_strlen(str)) != 0)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}

int	*save_dup_malloc(int i)
{
	int	*fd;

	fd = malloc(sizeof(int) * (i + 2));
	fd[i] = dup(1);
	fd[i + 1] = dup(0);
	return (fd);
}

int	ouble(char *str)
{
	if (!ft_strncmp(str, ">>", 2) || !ft_strncmp(str, ">", 1))
		return (1);
	return (0);
}

void	ouput_redirections(int	*fd, int j, char **str, int k)
{
	if (!ft_strncmp(str[j], ">", 1))
		redirect_output(0, fd, k, str[j + 1]);
	else if (!ft_strncmp(str[j], ">>", 2))
		redirect_output(1, fd, k, str[j + 1]);
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
