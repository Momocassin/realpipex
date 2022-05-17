/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:18:08 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:18:11 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execv(char **path, char **envp, char **argv)
{
	execkcheck(path, envp, argv);
	if (access(argv[0], X_OK) == 0)
	{
		execve(argv[0], argv, envp);
		perror("Can't execve");
		liberty(argv);
		exit(0);
	}
	else
	{
		write(2, "Can't find command", 19);
		liberty(argv);
		exit(0);
	}
}

void	execkcheck(char **path, char **envp, char **argv)
{
	int		i;
	char	*execpath;
	char	*tmp;

	execpath = NULL;
	tmp = NULL;
	i = 0;
	while (path[i] != NULL)
	{
		tmp = ft_strjoin(path[i], "/");
		execpath = ft_strjoin(tmp, argv[0]);
		free(tmp);
		if (access(execpath, X_OK) == 0)
		{
			execve(execpath, argv, envp);
			perror("Error execve");
			liberty(path);
			free(argv);
			free(execpath);
			exit(0);
		}
		free(execpath);
		i++;
	}
	liberty(path);
}
