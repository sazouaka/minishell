/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:47:31 by sazouaka          #+#    #+#             */
/*   Updated: 2019/11/23 22:47:33 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_pdenied(char **flag)
{
	DIR	*dir;

	dir = opendir(flag[1]);
	if (dir == NULL || access(flag[1], X_OK) != 0)
	{
		ft_putstr("cd: permission denied: ");
		ft_putstr(flag[1]);
		ft_putchar('\n');
		return (1);
	}
	closedir(dir);
	return (0);
}

void	ft_cd_home(t_lst *head)
{
	char	*buff;
	t_lst	*node;

	buff = (char *)malloc(sizeof(char) * 1000);
	node = head;
	while (node)
	{
		if (ft_strcmp(node->name, "HOME") == 0)
		{
			ft_change_d(head, "OLDPWD", getcwd(buff, 500));
			chdir(node->content);
			ft_change_d(head, "PWD", getcwd(buff, 500));
			free(buff);
			return ;
		}
		node = node->next;
	}
	ft_putstr("cd: no home directory.\n");
	free(buff);
}

void	ft_cd_1(char **flag, t_lst *head)
{
	char	*buff;

	if (ft_pdenied(flag))
		return ;
	buff = (char *)malloc(sizeof(char) * 1000);
	ft_change_d(head, "OLDPWD", getcwd(buff, 500));
	chdir(flag[1]);
	ft_change_d(head, "PWD", getcwd(buff, 500));
	free(buff);
}

void	ft_cd_2(char **flag)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putstr(flag[1]);
	ft_putchar('\n');
}

void	ft_cd(char **flag, t_lst *head)
{
	if (ft_strcmp(flag[1], ".") == 0)
		return ;
	if (verify_type(flag[1]) == 1)
		ft_cd_1(flag, head);
	else if (verify_type(flag[1]) == -1)
		ft_cd_2(flag);
	else if (verify_type(flag[1]) != 1)
	{
		ft_putstr("cd: not a directory: ");
		ft_putstr(flag[1]);
		ft_putchar('\n');
	}
}
