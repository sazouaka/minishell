/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:53:08 by sazouaka          #+#    #+#             */
/*   Updated: 2019/10/12 20:53:13 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_split(char *buff)
{
	int	i;
	int end;
	int start;
	int j;
	char **flags;

	flags = (char **)malloc(sizeof(char *) * SIZE);
	start = 0;
	i = 0;
	j = 0;
	while (buff[i] != '\0')
	{
		while ((buff[i] == ' ' || buff[i] == '\t') && buff[i] != '\0')
			i++;
		if (buff[i] == 34)
		{
			i++;
			start = i;
			end = 0;
			while (buff[i] != '\0' && buff[i] != 34)
			{
				i++;
				end++;
			}
			if(end)
			{
				flags[j] = ft_strsub(buff, start, end);
				j++;
			}
		}
		else if (buff[i] == 39)
		{
			i++;
			start = i;
			end = 0;
			while (buff[i] != '\0' && buff[i] != 39)
			{
				i++;
				end++;
			}
			if(end)
			{
				flags[j] = ft_strsub(buff, start, end);
				j++;
			}
		}
		else if (buff[i] != 39 && buff[i] != 34)
		{
			start = i;
			end = 0;
			while (buff[i] != ' ' && buff[i] != '\t' && buff[i] != '\0')
			{
				i++;
				end++;
			}
			if(end)
			{
				flags[j] = ft_strsub(buff, start, end);
				j++;
			}
		}
		i++; 
	}
	return (flags);
}
