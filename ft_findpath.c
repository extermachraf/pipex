/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:00:43 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:55 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char	**pa;
	int		i;

	i = 0;
	while (!(ft_strnstr(envp[i], "PATH", 4)))
		i++;
	pa = ft_split(envp[i] + 5, ':');
	return (pa);
}

char	*exep_path(char *cmd, char **envp)
{
	t_pip	p1;
	int		i;
	int		j;

	p1.pa = find_path(envp);
	i = -1;
	j = 0;
	p1.split_cmd = ft_split(cmd, ' ');
	if (!(access(p1.split_cmd[0], X_OK)))
	{
		return (p1.split_cmd[0]);
	}
	while (p1.pa[++i])
	{
		p1.sh = ft_strjoin(p1.pa[i], "/");
		p1.path = ft_strjoin(p1.sh, p1.split_cmd[0]);
		if (!(access(p1.path, X_OK)))
		{
			return (p1.path);
		}
	}
	perror("ton pate n'existe pas");
	return (0);
}
