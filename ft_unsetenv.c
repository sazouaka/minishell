/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 00:41:02 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/05 00:41:04 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv_1(char *flag, t_lst **head)
{
	t_lst	*node;
	t_lst	*tmp1;

	node = *head;
	while (node)
	{
		if (ft_strcmp(node->name, flag) == 0)
		{
			free(node->name);
			free(node->content);
			tmp1->next = node->next;
			free(node);
			return ;
		}
		tmp1 = node;
		node = node->next;
	}
}

void	ft_unsetenv(char **flag, t_lst **head)
{
	int i;

	if (flag[1] == NULL)
		ft_putstr("unsetenv: Too few arguments.\n");
	i = 1;
	while (flag[i])
	{
		if (ft_strcmp(flag[i], "#PATH_D") != 0)
			ft_unsetenv_1(flag[i], head);
		i++;
	}
}
