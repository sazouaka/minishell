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

void    ft_unsetenv(char **flag, t_lst **head)
{
	t_lst   *node;
	t_lst   *tmp1;
	t_lst   *tmp2;
	int     i;

	if (flag[1] == NULL)
		ft_putstr("unsetenv: Too few arguments.\n");
	i = 1;
	while (flag[i])
	{
		node = *head;
		tmp2 = (*head)->next;
		if (ft_strcmp(flag[i], "PATH_D") == 0)
		{
			i++;
			continue;
		}
		while (node)
		{
			if (ft_strcmp(node->name, flag[i]) == 0)
			{
				if (node == *head)
				{
					free((*head)->name);
					free((*head)->content);
					free(*head);
					*head = tmp2;
					break;
				}
				else
				{
					free(node->name);
					free(node->content);
					tmp1->next = node->next;
					free(node);
					break;
				}
			}
			tmp1 = node;
			node = node->next;
		}
		i++;
	}
}