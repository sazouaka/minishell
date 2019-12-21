/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 03:08:25 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/21 03:08:29 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_val_1(char *str, t_lst *head)
{
	t_lst	*node;

	node = head;
	while (node)
	{
		if (ft_strcmp(str, node->name) == 0)
		{
			free(str);
			return (node->content);
		}
		node = node->next;
	}
	free(str);
	return ("");
}

char	*get_var_val(char *str, int *end, t_lst *head)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_isalpha(str[0]) || str[0] == '_')
		i++;
	else
	{
		*end = 1;
		return ("");
	}
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
			break ;
	}
	*end = i;
	tmp = ft_strsub(str, 0, i);
	return (get_var_val_1(tmp, head));
}
