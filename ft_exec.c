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

	if (access(flag[0], F_OK) == 0)
		return (flag[0]);
	i = 0;
	while (paths[i])
	{
		if (access(ft_strjoin(paths[i], flag[0]), F_OK) == 0)
		{
			cmd_path = ft_strjoin(paths[i], flag[0]);
			return (cmd_path);
		}
		i++;
	}
	return (NULL);
}

void	ft_exec(char **flag, t_lst *env_list)
{
	char	*cmd_path;
	pid_t	pid;
	char	**paths;

	paths = ft_path(env_list);
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
		{
			execve(cmd_path, flag, env_tab_(env_list));
			ft_putstr(flag[0]);
			ft_putstr(": permission denied: \n");
		}
		wait(NULL);
	}
	else if (cmd_path == NULL || flag[0] == NULL)
	{
		ft_putstr(flag[0]);
		ft_putstr(": command not found. \n");
	}
}
