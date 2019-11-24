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

void	ft_cd(char **flag, t_lst *head)
{
	t_lst	*node;
	char	*tmp;
	int i;

	
	if (flag[1] && opendir(flag[1]))
	{
		chdir(flag[1]);
		node = head;
		while(node)
		{
			if (ft_strcmp(node->name, "PWD") == 0)
			{
				tmp = ft_strdup(ft_strjoin(node->content, "/"));
				free(node->content);
				node->content = ft_strdup(ft_strjoin(tmp, flag[1]));
			}
			node = node->next;
		}
	}
	else if (opendir(flag[1]) == NULL)
	{
		i = 0;
		while(flag[1][i])
			i++;
		write(1,"cd: no such file or directory: ",32);
		write(1, flag[1], i);
		write(1, "\n", 1);
	}
	else
		chdir("/Users/sazouaka");
}