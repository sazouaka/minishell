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
	sig = 0;
	ft_putstr("\x1B[35m");
	ft_putstr("\n$> ");
	ft_putstr("\x1b[39m");
	g_sign = 1;
}

void	ft_prompt()
{
	if (g_sign == 0)
	{
		ft_putstr("\x1B[35m");
		ft_putstr("$> ");
		ft_putstr("\x1b[39m");
	}
	else
		g_sign = 0;
}

void	free_list(t_lst *head)
{
	t_lst	*tmp;

	if (head == NULL)
		return;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp->content);
		free(tmp);
	}
}

void	free_tab(char **flag)
{
	int	i;

	i = 0;
	while (flag[i])
	{
		free(flag[i]);
		i++;
	}
	free(flag);
}

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
		return;
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
	if (ft_strcmp(flag[0], "env") == 0) /*a verifier la necessité de ft_strcmp(flag[0], "/usr/bin/env"..elle fonctionne bien sans cette condition !*/
	{
		if (flag[1])
		{
			ft_putstr("env: ");
			ft_putstr(flag[1]);
			ft_putstr(": No such file or directory\n");
		}
		else
			ft_printlist(env_list);
		return;
	}
	else if (ft_strcmp(flag[0], "echo") == 0)
		ft_echo(flag);
	else
		ft_builtins_2(flag, env_list);
}

int	main(int ac, char **av, char **env)
{
	char	*buff;
	char	**flag;
	t_lst	*env_list;
	char	*tmp;

	if (ac != 1 || ft_strcmp(av[0], "./minishell") != 0)
		return (0);
	signal(SIGINT, ft_signal);
	env_list = ft_env(env);
	g_sign = 0;
	while (1)
	{
		ft_prompt();
		get_next_line(0, &buff);
		if (ft_strcmp(buff, "") == 0)
		{
			free(buff);
			continue;
		}
		tmp = ft_parse(buff, env_list);
		free(buff);
		if (tmp == NULL)
		{
			ft_putstr("./minishell: permission denied:\n");
			continue;
		}
		flag = ft_strsplit(tmp, 31);
		free(tmp);
		if (flag[0] == NULL)
		{
			free_tab(flag);
			continue;
		}
		else
		{
			ft_builtins_1(flag, env_list);
			free_tab(flag);
		}	
	}
	return (0);
}
/* il reste un probleme quand je tape ctrl c et je tape entré ou j'ecrie clear le prompt se disparait */
/* le probleme de 1000 location dans ft_parse */