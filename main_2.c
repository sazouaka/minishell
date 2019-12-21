/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:46:22 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/21 23:46:23 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtins_2(char **flag, t_lst *env_list)
{
	if (ft_strcmp(flag[0], "cd") == 0)
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
		return ;
	}
	else if (ft_strcmp(flag[0], "setenv") == 0)
		ft_setenv(flag, env_list);
	else if (ft_strcmp(flag[0], "unsetenv") == 0)
		ft_unsetenv(flag, &env_list);
	else if (flag[0] && ft_strcmp("exit", flag[0]) == 0)
	{
		free_list(env_list);
		free_tab(flag);
		exit(0);
	}
	else
		ft_exec(flag, env_list);
}

void	ft_builtins_1(char **flag, t_lst *env_list)
{
	if (ft_strcmp(flag[0], "env") == 0)
	{
		ft_printlist(env_list);
		return ;
	}
	else if (ft_strcmp(flag[0], "echo") == 0)
		ft_echo(flag);
	else
		ft_builtins_2(flag, env_list);
}

void	main_2(char *tmp, t_lst *env_list)
{
	char	**flag;

	if (tmp == NULL)
	{
		ft_putstr("./minishell: permission denied:\n");
		return ;
	}
	flag = ft_strsplit(tmp, 31);
	free(tmp);
	if (flag[0] == NULL)
	{
		free_tab(flag);
		return ;
	}
	else
	{
		ft_builtins_1(flag, env_list);
		free_tab(flag);
	}
}
