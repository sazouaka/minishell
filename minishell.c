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

void	ft_signal(int sig)
{
	sig = 0;
	ft_putstr("\x1B[35m");
	ft_putstr("\n$> ");
	ft_putstr("\x1b[39m");
	g_sign = 1;
}

void	ft_prompt(void)
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

int		main(int ac, char **av, char **env)
{
	char	*buff;
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
			g_sign = 0;
			free(buff);
			continue;
		}
		tmp = ft_parse(buff, env_list);
		free(buff);
		main_2(tmp, env_list);
	}
	return (0);
}
