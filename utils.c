/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:17:12 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:17:20 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && n > i + 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

unsigned	int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	check(int argc, t_pipe *p, char **envp)
{
	if (argc != 5)
	{
		write(1, "Wrong number of arguments", 26);
		exit(0);
	}
	if (pipe(p->fd) == -1)
	{
		perror("Can't pipe");
		exit(0);
	}
	p->path = ft_getenv(envp);
	if (p->path == NULL)
	{
		perror("Can't get environment variable");
		exit(0);
	}
}

void	liberty(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
