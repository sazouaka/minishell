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

void	ft_cd_home(t_lst *head)
{
	t_lst	*node;

	chdir("/Users/sazouaka");
	node = head;
	while(node)
	{
		if (ft_strcmp(node->name, "OLDPWD") == 0)
		{
			free(node->content);
			node->content = ft_strdup(node->next->content);
		}
		if (ft_strcmp(node->name, "PWD") == 0)
		{
			free(node->content);
			node->content = ft_strdup("/Users/sazouaka");
		}
		node = node->next;
	}
}

int		verify_type(char *file)
{
	struct  stat    st;
	int             ret;

	if ((ret = lstat(file, &st)) == 0)
	{
		if (S_ISDIR(st.st_mode))
			return (1);
		else
			return (0);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int	ft_pdenied(char **flag)
{
	DIR	*dir;

	dir = opendir(flag[1]);
	if (dir == NULL)
	{
		ft_putstr("cd: permission denied: ");
		ft_putstr(flag[1]);
		ft_putchar('\n');
		return (1);
	}
	return(0);
}

void	ft_cd_1(char **flag, t_lst *head)
{
	t_lst	*node;
	char    *buff;

	if (ft_pdenied(flag))
		return;
	chdir(flag[1]);
	node = head;
	buff = (char *)malloc(sizeof(char) * 1000);
	while(node)
	{
		printf("******\n");
		if (ft_strcmp(node->name, "OLDPWD") == 0)
		{
			free(node->content);
			node->content = ft_strdup(node->next->content);
		}
		if (ft_strcmp(node->name, "PWD") == 0)
		{
			free(node->content);
			node->content = ft_strdup(getcwd(buff, 500));
		}
		node = node->next;
	}
}

void	ft_cd_2(char **flag)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putstr(flag[1]);
	ft_putchar('\n');
}

void	ft_cd(char **flag, t_lst *head)
{
	if (ft_strcmp(flag[1] , ".") == 0)
		return;
	if (verify_type(flag[1]) == 1)
		ft_cd_1(flag, head);
	else if (verify_type(flag[1]) == -1)
		ft_cd_2(flag);
	else if (verify_type(flag[1]) == 0)
	{
		ft_putstr("cd: not a directory: ");
		ft_putstr(flag[1]);
		ft_putchar('\n');
	}
}

