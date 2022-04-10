/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:36:26 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/02/19 17:59:31 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childe_2(int f2, int *end, char *cmd2, char **envp)
{
	char	*c;
	char	**h;

	c = exep_path(cmd2, envp);
	h = ft_split(cmd2, ' ');
	close(end[1]);
	dup2(f2, 1);
	dup2(end[0], 0);
	close(f2);
	close(end[0]);
	execve(c, h, envp);
}

void	childe_one(int f1, int *end, char *cmd1, char **envp)
{
	char	**h;
	char	*c;

	c = exep_path(cmd1, envp);
	h = ft_split(cmd1, ' ');
	close(end[0]);
	dup2(f1, 0);
	dup2(end[1], 1);
	close(f1);
	close(end[1]);
	execve(c, h, envp);
}

void	ret_er(void)
{
	perror("errrrrr");
	exit(1);
}

void	ft_pipex(int f1, int f2, t_cmmd *cmd, char **envp)
{
	int		end[2];
	pid_t	ch1;
	pid_t	ch2;

	pipe(end);
	ch1 = fork();
	if (ch1 < 0)
		ret_er();
	if (ch1 == 0)
		childe_one(f1, end, cmd->cmd1, envp);
	ch2 = fork();
	if (ch2 < 0)
		ret_er();
	if (ch2 == 0)
		childe_2(f2, end, cmd->cmd2, envp);
	close(end[0]);
	close(end[1]);
	wait(NULL);
	wait(NULL);
}

int	main(int ac, char **ag, char **envp)
{
	int		fd;
	int		fds;
	t_cmmd	*cmd;

	cmd = malloc(sizeof(t_cmmd));
	cmd->cmd1 = ag[2];
	cmd->cmd2 = ag[3];
	if (ac == 5)
	{
		fd = open(ag[1], O_RDONLY);
		fds = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd < 0 || fds < 0)
		{
			ret_er();
		}
		ft_pipex(fd, fds, cmd, envp);
		free(cmd);
	}
	return (0);
}
