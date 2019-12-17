/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:54:47 by sazouaka          #+#    #+#             */
/*   Updated: 2019/10/14 16:54:50 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*ft_get_node(char *str)
{
	t_lst	*node;
	int		i;

	node = (t_lst *)malloc(sizeof(t_lst));
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			node->name = ft_strsub(str, 0, i);
			break;
		}
		i++;
	}
	node->content = ft_strdup(&str[i + 1]);
	node->next = NULL;
	return (node);
}

t_lst  *ft_env(char **env)
{
	t_lst   *head;
	t_lst   *node;
	int     i;

	head = ft_get_node(PATH_D);
	i = 0;
	node = head;
	while (env[i])
	{
		node->next = ft_get_node(env[i]);
		node = node->next;
		i++;
	}
	return (head);
}

void    ft_printlist(t_lst *head)
{
    t_lst   *node;
	char	*name;
	char	*content;
	int		i;

    node = head->next;
    while (node)
    {
		i = 0;
		name = ft_strdup(node->name);
		while (name[i])
			i++;
        ft_putstr(name);
		ft_putchar('=');
		i = 0;
		content = ft_strdup(node->content);
		while (content[i])
			i++;
		ft_putstr(content);
		ft_putchar('\n');
        node = node->next;
    }
}
