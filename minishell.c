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

	env_list = ft_env(env);
	paths = ft_path(env_list);
	while (1)
	{
		write(1, "$> ", 3);
		get_next_line(0, &buff);
		flag = ft_strsplit(ft_parse(buff, env_list), 31);
		if (flag[0] == NULL)
			continue;
		if (ft_strcmp(flag[0], "env") == 0)
		{
			ft_printlist(env_list);
			continue;
		}
		if (ft_strcmp(flag[0], "cd") == 0)
		{
			ft_cd(flag, env_list);
			continue;
		}
		if (ft_strcmp("exit", flag[0]) == 0)
			exit(0);
		ft_exec(paths, flag);
	}
}

/*I still need to code (cd -) and permission denied*/
