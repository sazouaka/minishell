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

void    ft_cd_old(t_lst *head)
{
	char	*buff;
	char	*old_d;
	t_lst	*node;

	node = head;
	
	while (node)
	{
		if (ft_strcmp(node->name, "OLDPWD") == 0)
		{
			buff = (char *)malloc(sizeof(char) * 1000);
			old_d = node->content;
			ft_change_d(head, "OLDPWD", getcwd(buff, 500));
			chdir(old_d);
			ft_change_d(head, "PWD", getcwd(buff, 500));
			free(buff);
			return;
		}
		node = node->next;
	}
	ft_putstr(": No such file or directory.\n");
}