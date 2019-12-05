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

t_lst  *ft_env(char **env)
{
	t_lst   *head;
	t_lst   *node;
	int     i;
	int     j;
	int     end;
	int     start;

	node = NULL;
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		if (!node)
		{
			node = (t_lst *)malloc(sizeof(t_lst));
			node->name = ft_strsub(env[i], 0, j);
			j++;
			start = j;
			end = 0;
			while (env[i][j] != '\0')
			{
				j++;
				end++;
			}
			node->content = ft_strsub(env[i], start, end);
			node->next = NULL;
			head = node;
		}
		else
		{
			node->next = (t_lst *)malloc(sizeof(t_lst));
			node->next->name = ft_strsub(env[i], 0, j);
			j++;
			start = j;
			end = 0;
			while (env[i][j] != '\0')
			{
				j++;
				end++;
			}
			node->next->content = ft_strsub(env[i], start, end);
			node->next->next = NULL;
			node = node->next;
		}
		i++;
	}
	return (head);
}

void    ft_printlist(t_lst *list)
{
    t_lst   *node;
	char	*name;
	char	*content;
	int		i;

    node = list;
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
