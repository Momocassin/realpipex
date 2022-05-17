/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:17:38 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:17:40 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	boucle(char *s3, const char *s1, int i)
{
	int		p;
	int		y;

	p = 0;
	y = 0;
	while (p < i)
	{
		s3[p] = s1[y];
		p++;
		y++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		p;
	char	*s3;
	int		y;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	y = 0;
	p = 0;
	i = (int)ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (i + ft_strlen(s2) + 1));
	if (!s3)
		return (0);
	p = boucle(s3, s1, i);
	y = 0;
	while (p <= (int)(i + ft_strlen(s2) - 1))
	{
		s3[p] = s2[y];
		p++;
		y++;
	}
	s3[p] = '\0';
	return (s3);
}
