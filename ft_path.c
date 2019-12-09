/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:30:21 by sazouaka          #+#    #+#             */
/*   Updated: 2019/11/07 14:30:24 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_path(t_lst *head)
{
	char	**contenu;
	char	**path;
	t_lst	*node;
	int		i;

	node = head;
	while (node && (ft_strcmp(node->name, "PATH") != 0))
		node = node->next;
	if (node)
	{
		contenu = ft_strsplit(node->content, ':');
		i = 0;
		while (contenu[i])
			i++;
		path = (char **)malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (contenu[i])
		{
			path[i] = ft_strjoin(contenu[i], "/");
			free(contenu[i]);
			i++;
		}
		path[i] = NULL;
		free(contenu);
		return (path);
	}
	else
		return(ft_strsplit(PATH_D, ':'));
}
