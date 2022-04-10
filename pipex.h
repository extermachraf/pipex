/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:00:50 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/02/19 18:09:27 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>

typedef struct pipex
{
	char	**pa;
	char	*path;
	char	*sh;
	char	**split_cmd;
}t_pip;

typedef struct command
{
	char	*cmd1;
	char	*cmd2;
}t_cmmd;

char	*ft_strjoin(char const	*s1, char const	*s2);
int		ft_strlen(const char	*s);
char	**ft_split(char const *s, char c);
char	*exep_path(char *cmd, char **envp);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**find_path(char **envp);
char	**ft_split_cmd(char *cmd);
void	childe_one(int f1, int *end, char *cmd1, char **envp);
void	childe_one(int f1, int *end, char *cmd1, char **envp);
void	ret_er(void);
#endif
