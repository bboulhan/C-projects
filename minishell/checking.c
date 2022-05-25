/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:55:06 by bboulhan          #+#    #+#             */
/*   Updated: 2022/05/23 17:55:19 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quote(char *line, int *i)	
{
	int	j;

	j = *i + 1;
	while (line[j] != line[*i] && line[j])
		j++;
	*i = j;
	return (ft_substr(line, *i, j));
}

void	checker(char *line, t_list **node)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	*node->table = malloc(sizeof(char *) * 1);
	if (!(*node->table))
		return (NULL);
	while (line[i])
	{
		if (line[i] == 39 || line[i] == '"')
		{
			*node->table[j++] = quote(line, &i);
			if (!ft_realloc(*node->table, j))
				return ;
		}
		if (line[i] == '|' || !line[++i])
			break;
	}
	*node->table[j] = NULL;

}

void	lexer(char *line, t_list **node)
{
	int	i;

	i = 0;
	while (line)
}
