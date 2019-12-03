/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_old.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:33:31 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/03 21:33:45 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_setenv(char **flag, t_lst *head)
{
    t_lst	*node;

    if (flag[1] == NULL)
    {
        ft_printlist(head);
		return;
    }
    else
    {
        while(node)
        {
            if (ft_strcmp(node->name, flag[1]) == 0)
                free(node->content);
            node = node->next;
        }
        // node->name = ft_strdup(ft_strjoin(flag[1], "="));
        // node->content = NULL;
        // node->next = NULL;
        /* Ineed to fix this part... see your notebook */

    }
}