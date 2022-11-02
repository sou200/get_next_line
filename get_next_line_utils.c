/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serhouni <serhouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:45:52 by serhouni          #+#    #+#             */
/*   Updated: 2022/10/31 23:13:42 by serhouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1l;
	size_t	s2l;
	size_t	i;
	size_t	j;
	char	*p;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	i = 0;
	j = 0;
	p = malloc((s1l + s2l + 1) * sizeof(char));
	if (p == 0)
		return (0);
	while (j < s1l)
		p[i++] = s1[j++];
	j = 0;
	while (j < s2l)
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (i < n)
		p[i++] = '\0';
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	size;
	void	*p;

	size = nelem * elsize;
	if (nelem != 0 && (size / nelem) != elsize)
		return (0);
	p = malloc(size);
	if (p == 0)
		return (0);
	ft_bzero(p, size);
	return (p);
}
