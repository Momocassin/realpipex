/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:17:03 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:17:22 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <memory.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_pipe
{
	char	**argv;
	char	**envp;
	int		in;
	int		out;
	int		fd[2];
	int		child2;
	int		child;
	char	**cmd;
	char	**cmdd;
	char	**path;
}				t_pipe;

void			ft_execv(char **path, char **envp, char **argv);
void			liberty(char **str);
char			**ft_getenv(char **env);
void			check(int argc, t_pipe *p, char **envp);
void			execkcheck(char **path, char **envp, char **argv);
void			checkexec(char **path, char **envp, char **argv);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned int	ft_strlen(const char *c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);

#endif