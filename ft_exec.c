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

int		is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return(1);
		i++;
	}
	return(0);
}

char	*ft_access(char **paths, char **flag)
{
	int		i;
	char	*cmd_path;

	if (access(flag[0], F_OK) == 0 && verify_type(flag[0]) == 2 && is_path(flag[0]))
		return (flag[0]);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], flag[0]);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	ft_exec(char **flag, t_lst *env_list)
{
	char	*cmd_path;
	pid_t	pid;
	char	**paths;
	char	**env_tab;

	paths = ft_path(env_list);
	cmd_path = ft_access(paths, flag);
	free_tab(paths);
	if (cmd_path != NULL)
	{
		pid = fork();
		if (fork < 0)
		{
			ft_putstr("fork failed\n");
			exit(1);
		}
		else if (pid == 0)
		{
			env_tab = env_tab_(env_list);
			execve(cmd_path, flag, env_tab);
		}
		if (ft_strcmp(cmd_path, flag[0]) != 0)
			free(cmd_path);
		wait(NULL);
	}
	else 
	{
		if (access(flag[0], F_OK) == 0 && verify_type(flag[0]) == 1 && is_path(flag[0]))
		{
			ft_putstr(flag[0]);
			ft_putstr(": permission denied.\n");
			return;
		}
		ft_putstr(flag[0]);
		ft_putstr(": command not found.\n");
	}
}