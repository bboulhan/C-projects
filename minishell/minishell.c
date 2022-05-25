/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboulhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:18:35 by bboulhan          #+#    #+#             */
/*   Updated: 2022/05/20 16:19:13 by bboulhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(char *line)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (line[i])
	{
		if (line[i] == '|')
			y++;
		i++;
	}
	return (y);
}

void	print(t_list *node)
{
	int i = 0;

	while (node)
	{
		while (node->table[i])
			printf("%s&\n", node->table[i++]);
		printf("--------------------\n");
		i = 0;
		node = node->next;
	}

}

int	main(void)
{
	t_list	*node;
	char	*line;
	//int		pid;

	line = NULL;
	node = NULL;
	node = malloc(sizeof(t_list) * 1);
	node->next = NULL;
	// while (1)
	// {
	// 	pid = fork();
	// 	if (pid == 0)
	// 	{
	// 		line = readline("~$ ");
	// 		//checker(line, &node);
	// 		//print(node);
	// 	}
	// }
	while (1)
	{	
		line = readline("~$ ");
		checker(line, &node);
		//print(node);
	}
}



// int	main(void)
// {
// 	char	**argv;
// 	char	*path[] = { "/bin/", "/bin/sh"};
// 	int		pid;

// 	while (1)
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			argv = ft_split(readline("~$ "), ' ');
// 			if (execve(ft_strjoin(path[0], argv[0]), argv, NULL) == -1
// 				&& execve(path[1], argv, NULL) == -1)
// 			{
// 				perror("");
// 			}
// 			ft_free(argv);
// 		}
// 		wait(NULL);
// 	}
// 	return (0);
// }

