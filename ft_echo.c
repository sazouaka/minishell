/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:36:18 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/05 16:36:20 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **flag)
{
	int	i;

	i = 1;
	if (flag[1] == NULL)
	{
		ft_putchar('\n');
		return ;
	}
	if (flag[1] && ft_strcmp(flag[1], "-n") == 0)
		i++;
	while (flag[i])
	{
		ft_putstr(flag[i]);
		if (flag[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	if (ft_strcmp(flag[1], "-n") == 0)
		return ;
	else
		ft_putchar('\n');
}
