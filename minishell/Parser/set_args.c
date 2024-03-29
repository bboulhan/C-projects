/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <bboulhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:03:28 by bboulhan          #+#    #+#             */
/*   Updated: 2022/07/04 11:37:33 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_value(char *s, char *str, int *x, int *y)
{
	int		i;
	int		j;
	char	*env;

	env = NULL;
	i = *x;
	j = *y;
	j++;
	env = ft_substr(str, j, (i - j));
	env = get_env(env);
	j = -1;
	while (env[++j])
		s = add_char(s, env[j]);
	j = i;
	free(env);
	*x = i;
	*y = j;
	return (s);
}

char	*dollar_and_quote(char *s, char *str, int *i, int *j)
{
	*j = *i;
	*i = quoted(str, *i);
	if (str[*j] != str[*i])
		return (ft_error(0, NULL, NULL));
	if (str[*j] == '"')
	{
		if (check_dollar(str, *j, *i))
		{
			if (ft_isalnum(str[check_dollar(str, *j, *i) + 1]))
			{	
				*j = check_dollar(str, *j, *i) + 1;
				while ((*j)++ < *i - 1)
					s = add_char(s, str[*j]);
			}
			else
				s = get_env_value(s, str, i, j);
		}
	}
	if (*j != *i)
	{
		while ((*j)++ < *i - 1)
			s = add_char(s, str[*j]);
	}
	return (s);
}

char	*only_dollar(char *s, char *str, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	if (str[i] == '$' && str[i + 1] && (ft_isalpha(str[i + 1])
			|| str[i + 1] == '_' || str[i + 1] == '?'))
	{
		j = i++ - 1;
		while (str[i] && (ft_isalnum(str[i])
				|| ft_isalpha(str[i]) || str[i] == '_' || str[i] == '?'))
			i++;
		s = get_env_value(s, str, &i, &j);
		i--;
	}
	else if (str[i] == '$' && str[i + 1] && (str[i + 1] != 39
			&& str[i + 1] != '"'))
		i++;
	else if (str[i] == '$' && !str[i + 1])
		s = add_char(s, str[i]);
	else if (str[i] != '$')
		s = add_char(s, str[i]);
	*x = i;
	*y = j;
	return (s);
}

char	*put_arg(char *str)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = ft_calloc(1, 1);
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 39 || str[i] == '"')
			s = dollar_and_quote(s, str, &i, &j);
		else
			s = only_dollar(s, str, &i, &j);
		i++;
	}
	return (s);
}
