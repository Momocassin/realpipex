/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 01:18:18 by motaouss          #+#    #+#             */
/*   Updated: 2021/09/03 01:18:19 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;
	size_t			x;

	x = 0;
	copy = (unsigned char *)b;
	while (x < len)
	{
		copy[x] = (unsigned char)c;
		x++;
	}
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	tab = malloc(size * nmemb);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, nmemb);
	return (tab);
}
