/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:16:46 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:16:54 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	firstchild(t_pipe *p)
{
	p->child = fork();
	if (p->child < 0)
		perror("Can't fork");
	if (p->child == 0)
	{
		p->in = open(p->argv[1], O_RDONLY);
		if (p->in <= 1)
			perror("no file");
		close(p->fd[0]);
		dup2(p->in, STDIN_FILENO);
		dup2(p->fd[1], STDOUT_FILENO);
		close(p->fd[1]);
		p->cmdd = ft_split(p->argv[2], ' ');
		ft_execv(p->path, p->envp, p->cmdd);
	}
}

static	void	secondchild(t_pipe *p)
{
	p->child2 = fork();
	if (p->child2 < 0)
		perror("Can't Fork");
	if (p->child2 == 0)
	{
		p->out = open(p->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (p->out <= 1)
			perror("Can't create file");
		close(p->fd[1]);
		dup2(p->fd[0], 0);
		dup2(p->out, 1);
		close(p->fd[0]);
		p->cmd = ft_split(p->argv[3], ' ');
		ft_execv(p->path, p->envp, p->cmd);
	}
}

static	void	initp(t_pipe *p, char **argv, char **envp)
{
	p->cmd = NULL;
	p->cmdd = NULL;
	p->in = 0;
	p->out = 0;
	p->path = NULL;
	p->argv = argv;
	p->envp = envp;
	p->child2 = 0;
	p->child = 0;
}

void	run(t_pipe *p)
{
	firstchild(p);
	secondchild(p);
	close(p->fd[0]);
	close(p->fd[1]);
	waitpid(p->child, NULL, 0);
	waitpid(p->child2, NULL, 0);
	liberty(p->path);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p;

	initp(&p, argv, envp);
	check(argc, &p, envp);
	run(&p);
	return (0);
}
