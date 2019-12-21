/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_old.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:33:31 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/03 21:33:45 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_set_alnum(char **flag)
{
	int i;

	i = 1;
	while (flag[1][i])
	{
		if (!(ft_isalnum(flag[1][i])) && flag[1][i] != '_')
		{
			ft_putstr("setenv: Variable name must ");
			ft_putstr("contain alphanumeric characters.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_set_node(char **flag, t_lst *head)
{
	t_lst	*node;

	node = head;
	while (node)
	{
		if (ft_strcmp(node->name, flag[1]) == 0)
		{
			if (flag[2] == NULL)
			{
				free(node->content);
				node->content = ft_strdup("");
			}
			else
			{
				free(node->content);
				node->content = ft_strdup(flag[2]);
			}
			return (1);
		}
		node = node->next;
	}
	return (0);
}

void	ft_set_lastnode(char **flag, t_lst *head)
{
	t_lst	*node;

	node = head;
	while (node->next)
		node = node->next;
	node->next = (t_lst *)malloc(sizeof(t_lst));
	node = node->next;
	node->name = ft_strdup(flag[1]);
	if (flag[2] == NULL)
		node->content = ft_strdup("");
	else
		node->content = ft_strdup(flag[2]);
	node->next = NULL;
}

void	ft_setenv(char **flag, t_lst *head)
{
	if (flag[1] != NULL && flag[2] != NULL && flag[3] != NULL)
		ft_putstr("setenv: Too many arguments.\n");
	else
	{
		if (flag[1] == NULL)
		{
			ft_printlist(head);
			return ;
		}
		else
		{
			if (!(ft_isalpha(flag[1][0])) && flag[1][0] != '_')
			{
				ft_putstr("setenv: Variable name must begin with a letter.\n");
				return ;
			}
			else if (ft_set_alnum(flag) == 1)
				return ;
			else if (ft_set_node(flag, head) == 1)
				return ;
			ft_set_lastnode(flag, head);
		}
	}
}
