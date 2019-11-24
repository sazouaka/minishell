/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:32:24 by sazouaka          #+#    #+#             */
/*   Updated: 2019/11/07 16:32:30 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_access(char **paths, char **flag)
{
	int		i;
	char	*cmd_path;

	if (access(flag[0], X_OK) == 0)
		return (flag[0]);
	i = 0;
	while (paths[i])
	{
		if (access(ft_strjoin(paths[i], flag[0]), X_OK) == 0)
		{
			cmd_path = ft_strjoin(paths[i], flag[0]);
			return (cmd_path);
		}
		i++;
	}
	return (NULL);
}

void	ft_exec(char **paths, char **flag)
{
	char	*cmd_path;
	pid_t	pid;

	cmd_path = ft_access(paths, flag);
	if (cmd_path)
	{
		pid = fork();
		if (fork < 0)
		{
			ft_putstr("fork failed\n");
			exit(1);
		}
		else if (pid == 0)
			execv(cmd_path, flag);
		wait(NULL);
	}
	else if (cmd_path == NULL)
	{
		ft_putstr("Minishell: command not found: ");
		ft_putstr(flag[0]);
		ft_putchar('\n');
	}
}
