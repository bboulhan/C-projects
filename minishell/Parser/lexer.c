/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:06:25 by bboulhan          #+#    #+#             */
/*   Updated: 2022/06/24 09:51:08 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	lexer(char *line, t_list *node)
{
	t_list	*tmp;
	char	**par;

	tmp = node;
	par = lexer_pipe(line);
	if (!par)
		return 0;
	tmp->str = ft_strdup(par[0]);
	tmp->table = lexer_space(par[0]);
	if (!(tmp->table) || !(tmp->table[0]))
	{
		ft_free(par);
		return (0);
	}
	if (!lexer2(node, tmp, par))
		return (0);
	ft_free(par);
	return (1);
}

void	lexer_pipe_2(char *line, char ***t, int *i, int *n)
{
	int		j;
	char	**table;
	
	j = 0;
	table = *t;
	while (table[j])
		j++;
	if ((line[*i] == '|' && line[*i - 1] != '|') || line[*i + 1] == '\0')
	{
		j++;
		table = ft_realloc(table, j);
		if (line[*i] == '|')
			table[j - 1] = cut_string(line, *n, *i);
		else if (line[*i + 1] == '\0')
			table[j - 1] = cut_string(line, *n, *i + 1);
		*n = *i + 1;
		table[j] = NULL;
	}
	*t = table;
}

char	**lexer_pipe(char *line)
{
	int		i;
	int		n;
	char	**table;

	i = -1;
	n = 0;
	table = malloc(sizeof(char *) * 1);
	if (!table)
		return (NULL);
	table[0] = NULL;
	while (line[++i])
	{
		if (line[i] == 39 || line[i] == '"')
		{	
			i = quoted(line, i);
			if (i == 0)
				return (ft_error(4, table, NULL));
		}
		lexer_pipe_2(line, &table, &i, &n);
	}
	return (table);
}

void	lexer_space_2(char *line, char ***t, int *i, int *n)
{
	int		j;
	char	**table;
	
	j = 0;
	table = *t;
	while (table[j])
		j++;
	if ((line[*i] == ' ' && line[*i - 1] != ' ') || line[*i + 1] == '\0')
	{
		j++;
		table = ft_realloc(table, j);
		if (line[*i] == ' ')
			table[j - 1] = cut_string(line, *n, *i);
		else if (line[*i + 1] == '\0')
			table[j - 1] = cut_string(line, *n, *i + 1);
		*n = *i + 1;
		table[j] = NULL;
	}
	*t = table;
}

char	**lexer_space(char *line)
{
	int		i;
	int		n;
	char	**table;
	i = -1;
	n = 0;
	table = malloc(sizeof(char *) * 1);
	if (!table)
		return (NULL);
	table[0] = 0;
	while (line[++i])
	{
		if (line[i] == 39 || line[i] == '"')
		{	
			i = quoted(line, i);
			if (i == 0)
				return (ft_error(4, table, NULL));
		}
		lexer_space_2(line, &table, &i, &n);
	}
	return (table);
}








// if ((line[i] == ' ' && line[i - 1] != ' ') || line[i + 1] == '\0')
// 		{	
// 		j++;
// 		table = ft_realloc(table, j);
// 		if (line[i] == ' ')
// 			table[j - 1] = cut_string(line, n, i);
// 		else if (line[i + 1] == '\0')
// 			table[j - 1] = cut_string(line, n, i + 1);
// 		n = i + 1;
// 		table[j] = NULL;
// 		}




// int	put_zero(void *arg, int x, int y)
// {
// 	char	**table;
// 	char	*str;

// 	table = NULL;
// 	str = NULL;
// 	if (x == 1)
// 	{
// 		table = malloc(sizeof(char *) * 1);
// 		table[0] = ft_calloc(1, 1);
// 		arg = table;
// 	}
// 	else
// 	{
// 		str = ft_calloc(1, 1);
// 		arg = str;
// 	}
// 	return (y);
// }