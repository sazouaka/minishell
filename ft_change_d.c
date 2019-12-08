/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:43:28 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/08 16:43:30 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_change_d(t_lst *head, char *str1, char *str2)
{
    t_lst	*node;

    node = head;
    while (node)
    {
        if (ft_strcmp(node->name, str1) == 0)
        {
            free(node->content);
            node->content = ft_strdup(str2);
            return;
        }
        node = node->next;
    }
    node = head;
    while(node->next)
        node = node->next;
    node->next = (t_lst *)malloc(sizeof(t_lst));
    node = node->next;
    node->name = ft_strdup(str1);
    node->content = ft_strdup(str2);
    node->next = NULL;
}
