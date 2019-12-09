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
    int     i;

    node = NULL;
    if (flag[1] != NULL && flag[2] != NULL && flag[3] != NULL)
        ft_putstr("setenv: Too many arguments.\n");
    else
    {
        if (flag[1] == NULL)
        {
            ft_printlist(head);
            return;
        }
        else
        {
            if (!(ft_isalpha(flag[1][0])) && flag[1][0] != '_')
            {
                ft_putstr("setenv: Variable name must begin with a letter.\n");
                return;
            }
            i = 1;
            while (flag[1][i])
            {
                if (!(ft_isalnum(flag[1][i])) && flag[1][i] != '_')
                {
                    ft_putstr("setenv: Variable name must contain alphanumeric characters.\n");
                    return;
                }
                i++;
            }
            node = head;
            while(node)
            {
                if (ft_strcmp(node->name, flag[1]) == 0)
                {
                    if (flag[2] == NULL)
                    {
                        free(node->content);
                        node->content = ft_strdup("");
                    }
                    else
                    {
                        free(node->content);
                        node->content = ft_strdup(flag[2]);
                    }
                    return;
                }   
                node = node->next;
            }
            node = head;
            while(node->next)
                node = node->next;
            node->next = (t_lst *)malloc(sizeof(t_lst));
            node = node->next;
            node->name = ft_strdup(flag[1]);
            if (flag[2] == NULL)
                node->content = ft_strdup("");
            else
                node->content = ft_strdup(flag[2]);
            node->next = NULL;
        }
    }
}