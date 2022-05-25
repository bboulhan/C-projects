/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:06:25 by bboulhan          #+#    #+#             */
/*   Updated: 2022/05/25 12:06:51 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char	*cut_string(char *str, int i0, int i1)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(i1 - i0 + 1);
	if (!line)
		return (NULL);
	while (str[i0 + i] && i + i0 < i1)
	{
		line[i] = str[i0 + i];
		i++;
	}
	line[i] = 0;
	return (ft_strtrim(line, " "));
}

int	single_quoted(char	*line, int i)
{
	i++;
	while (line[i] != 39 && line[i])
		i++;
	return (i);
}

int	double_quoted(char	*line, int i)
{
	i++;
	while (line[i] != '"' && line[i])
		i++;
	return (i);
}

/*void	find_pipe(int *j, char *line, char **table, int i, int *n)
{
	j++;
	table = ft_realloc(table, j);
	if (line[i] == '|')
		table[j - 1] = cut_string(line, n, i);
	else if (line[i + 1] == '\0')
		table[j - 1] = cut_string(line, n, i + 1);
	n = i + 1;
}*/

/*char	**lexer(char *line)
{
	int		i;
	int		j;
	int		n;
	char	**table;

	i = -1;
	j = 0;
	n = 0;
	table = malloc(sizeof(char *) * 1);
	if (!table)
		return (NULL);
	table[0] = NULL;
	while (line[++i])
	{
		if (line[i] == '"')
			i = double_quoted(line, i);
		else if (line[i] == 39)
			i = single_quoted(line, i);
		if (line[i] == '|' || line[i + 1] == '\0')
		{
			j++;
			table = ft_realloc(table, j);
			if (line[i] == '|')
				table[j - 1] = cut_string(line, n, i);
			else if (line[i + 1] == '\0')
				table[j - 1] = cut_string(line, n, i + 1);
			n = i + 1;
		}
		table[j] = NULL;
	}
	return (table);
}*/