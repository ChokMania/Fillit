/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judumay <judumay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:45:56 by judumay           #+#    #+#             */
/*   Updated: 2018/12/06 14:45:55 by judumay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <string.h>
#include <unistd.h>

void	*ft_memcpy(char *dst, char *src, size_t n, int k)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char*)src)[i] == '#')
			((char*)dst)[i] = 'A' + k;
		else
			((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putendl(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (!(str = (char*)malloc(sizeof(str) * (i))))
		return (NULL);
	while (j <= i)
	{
		str[j] = s1[j];
		j++;
	}
	return (str);
}
