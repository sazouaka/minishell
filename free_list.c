/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:07:07 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/21 22:07:14 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_lst *head)
{
	t_lst	*tmp;

	if (head == NULL)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->name);
		free(tmp->content);
		free(tmp);
	}
}
