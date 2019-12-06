/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:05:10 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/06 16:05:12 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_count(t_lst *head)
{
	t_lst   *node;
	int		i;
	
	node = head;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

char    **env_tab_(t_lst *head)
{
	char    **env_tab;
	t_lst   *node;
	int		i;
	
	env_tab = (char **)malloc(sizeof(char *) * (ft_count(head) + 1));
	node = head;
	i = 0;
	while (node)
	{
		env_tab[i] = ft_strjoin(node->name, "=");
		env_tab[i] = ft_strjoin(env_tab[i], node->content);
		node = node->next;
		i++;
	}
	env_tab[i] = NULL;
	return (env_tab);
}
