/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:44:46 by bboulhan          #+#    #+#             */
/*   Updated: 2022/05/23 20:45:00 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
char	*cut_string(char *str, int i0, int i1)
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

char	*quote(char *line, int *i)	
{
	int		j;
	char	*x;

	j = *i + 1;
	while (line[j] != line[*i] && line[j])
		j++;
	x = ft_substr(line, *i, j - *i + 1);
	*i = j + 1;
	return (x);
}

char	*space(char *line, int *i)
{
	int		j;
	char	*x;

	j = *i;
	while (line[j])
	{
		if (line[j] == ' ' || line[j] == 39 || line[j] == '"')
			break ;
		j++;
	}
	x = ft_substr(line, *i, j - *i);
	*i = j;
	return (x);
}


void	add_stack(t_list **node, char *line, int *k)
{
	int		i;
	int		j;
	t_list	*new;

	i = *k;
	j = 0;
	new = malloc(sizeof(t_list) * 1);
	if (!new)
		exit (0);
	new->table = malloc(sizeof(char *) * 1);
	if (!new->table)
		exit (0);
	while (line[++i])
	{
		if (line[i] == 39 || line[i] == '"')
			new->table[j++] = quote(line, &i);
		else if (line[i] == '|')
			break ;
		else if (line[i] != ' ')
			new->table[j++] = space(line, &i);
	}
	printf("%s\n", new->table[0]);
	new->table[j] = ft_calloc(1, 1);
	new->table[j] = NULL;
	ft_lstadd_back(node, new);
	*k = i;
}

void	checker(char *line, t_list **node)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = -1;
	j = 0;
	tmp = *node;
	tmp->table = malloc(sizeof(char *) * 1);
	if (!tmp->table)
		return ;
	while (line[++i])
	{
		if (line[i] == 39 || line[i] == '"')
		{
			tmp->table[j] = quote(line, &i);
			printf("%s$\n", tmp->table[j]);
			j++;
		}
		else if (line[i] == '|')
		{
			tmp->table[j] = NULL;
			add_stack(&tmp, line, &i);
		}
		else if (line[i] != ' ')
		{
			tmp->table[j] = space(line, &i);
			printf("%s$\n", tmp->table[j]);
			j++;
		}
		//printf("%d\t%d\t%zu\n", i, j, ft_strlen(line));

	}
	printf("%s\n", tmp->table[0]);
	tmp->table[j] = ft_calloc(1, 1);
	tmp->table[j] = NULL;
	
}

// void	lexer(char *line, t_list **node)
// {
// 	int	i;

// 	i = 0;
// 	while (line)
// }
