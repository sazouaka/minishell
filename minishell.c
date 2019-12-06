/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:51 by sazouaka          #+#    #+#             */
/*   Updated: 2019/10/10 16:51:53 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*buff;
	char	**flag;
	char	**paths;
	t_lst	*env_list;
	char	**env_tab;

	if (ac != 1 || ft_strcmp(av[0], "./minishell") != 0)
		return (0);
	signal(SIGINT, ft_exit);
	env_list = ft_env(env);
	env_tab = env_tab_(env_list);
	paths = ft_path(env_list);
	while (1)
	{
		ft_putstr("\x1B[35m");
		ft_putstr("$> ");
		ft_putstr("\x1b[39m");
		get_next_line(0, &buff);
		flag = ft_strsplit(ft_parse(buff, env_list), 31);
		if (flag[0] == NULL)
			continue;
		if (ft_strcmp(flag[0], "env") == 0 || ft_strcmp(flag[0], "/usr/bin/env") == 0)
		{
			if (flag[1])
			{
				ft_putstr("env: ");
				ft_putstr(flag[1]);
				ft_putstr(": No such file or directory\n");
			}
			else
				ft_printlist(env_list);
			continue;
		}
		else if (ft_strcmp(flag[0], "echo") == 0)
			ft_echo(flag);
		else if (ft_strcmp(flag[0], "cd") == 0)
		{
			if (flag[1] == NULL)
				ft_cd_home(env_list);
			else
			{
				if (ft_strcmp(flag[1], "-") == 0)
					ft_cd_old(env_list);
				else
					ft_cd(flag, env_list);
			}
			continue;
		}
		else if (ft_strcmp(flag[0], "setenv") == 0)
			ft_setenv(flag, env_list);
		else if (ft_strcmp(flag[0], "unsetenv") == 0)
			ft_unsetenv(flag, &env_list);
		else if (flag[0] && ft_strcmp("exit", flag[0]) == 0)
			exit(0);
		else
			ft_exec(paths, flag, env_tab);
	}
	return (0);
}
