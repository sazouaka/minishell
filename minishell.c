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

int		g_sign;

void    ft_signal(int sig)
{

	sig = 1;
	ft_putstr("\x1B[35m");
	ft_putstr("\n$> ");
	ft_putstr("\x1b[39m");
	g_sign = 1;
}

int	main(int ac, char **av, char **env)
{
	char	*buff;
	char	**flag;
	t_lst	*env_list;

	if (ac != 1 || ft_strcmp(av[0], "./minishell") != 0)
		return (0);
	signal(SIGINT, ft_signal);
	env_list = ft_env(env);
	g_sign = 0;
	while (1)
	{
		if (g_sign == 0)
		{
			ft_putstr("\x1B[35m");
			ft_putstr("$> ");
			ft_putstr("\x1b[39m");
		}
		else
			g_sign = 0;
		get_next_line(0, &buff);
		flag = ft_strsplit(ft_parse(buff, env_list), 31);
		if (flag[0] == NULL)
			continue;
		if (ft_strcmp(flag[0], "env") == 0 || ft_strcmp(flag[0], "/usr/bin/env") == 0) /*a verifier la necessité de 
														ft_strcmp(flag[0], "/usr/bin/env"..elle fonctionne bien sans cette condition !*/
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
			ft_exec(flag, env_list);
	}
	return (0);
}
