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

void    ft_unsetenv(char **flag, t_lst *head)
{
    t_lst   *node;
    t_lst   *tmp;
    int     i;

    i = 1;
    while (flag[i])
    {
        node = head;
        while (node)
        {
            if (ft_strcmp(node->name, flag[i]) == 0)
            {
                free(node->name);
                free(node->content);
                tmp->next = node->next;
                free(node);
                break;
            }
            tmp = node;
            node = node->next;
        }
        i++;
    }
}