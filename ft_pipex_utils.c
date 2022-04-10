/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:34:55 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/02/19 17:35:46 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	j = 0;
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	char	*hay;
	char	*nee;
	int		i;
	int		j;

	if (len == 0 && !haystack && needle)
		return (NULL);
	hay = (char *)haystack;
	nee = (char *)needle;
	i = 0;
	if (nee[0] == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] && hay[i + j] == nee[j] && (j + i) < len)
		{
			if (nee[j + 1] == '\0')
				return (&hay[i]);
			j++;
		}
		i++;
	}
	return (0);
}
