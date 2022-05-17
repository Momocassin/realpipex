/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:17:58 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:18:00 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_getenv(char **env)
{
	int		i;
	int		m;
	char	*allpath;
	char	**spath;

	allpath = NULL;
	m = 0;
	i = 0;
	spath = NULL;
	while (env[i] != NULL && ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	if (ft_strncmp("PATH", env[i], 4) == 0)
	{
		m = ft_strlen(env[i]);
		allpath = ft_substr(env[i], 5, m);
		spath = ft_split(allpath, ':');
		free(allpath);
		return (spath);
	}
	return (NULL);
}
