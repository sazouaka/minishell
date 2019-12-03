/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_old.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:51:31 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/03 16:51:33 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd_old(char **flag, t_lst *head)
{
    t_lst	*node;
    char    *buff;

	node = head;
    buff = (char *)malloc(sizeof(char) * 1000);
	while(node)
	{
		if (ft_strcmp(node->name, "OLDPWD") == 0)
		{
	        chdir(node->content);
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