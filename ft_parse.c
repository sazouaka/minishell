/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:59:20 by sazouaka          #+#    #+#             */
/*   Updated: 2019/11/09 21:59:22 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char	*get_var_val(char *str, t_lst *head)
{
	t_lst	*node;

	node = head;
	while (node)
	{
		if (ft_strcmp(str, node->name) == 0)
			return (ft_strdup(node->content));
		node = node->next;
	}
	return (NULL);
}

char *ft_parse(char *buff, t_lst *head)
{
	int		i;
	int		j;
	int		start;
	int		end;
	char	*str;
	char	*val;

	str = (char *)malloc(sizeof(char) * 1000);
	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == 34 && buff[i + 1] == 34)
		{
			str[j] = 31;
			return (str);
		}
		if (buff[i] && (buff[i] == ' ' || buff[i] == '\t'))
		{
			str[j] = 31;
			j++;
			i++;
		}
		else if (buff[i] == 39)
		{
			i++;
			while (buff[i] && buff[i] != 39)
			{
				str[j] = buff[i];
				j++;
				i++;
			}
			i++;
		}
		else if (buff[i] == 34)
		{
			i++;
			if (buff[i] == '$')
			{
				i++;
				start = i;
				end = 0;
				while (isalnum(buff[i]) || buff[i] == '_')
				{
					i++;
					end++;
				}
				val = get_var_val(ft_strsub(buff, start, end), head);
				end = 0;
				while (val[end])
				{
					str[j] = val[end];
					end++;
					j++;
				}
			}
			while (buff[i] && buff[i] != 34)
			{
				str[j] = buff[i];
				j++;
				i++;
			}
			i++;
		}
		else if (buff[i] == '$')
		{
			i++;
			start = i;
			end = 0;
			while (isalnum(buff[i]) || buff[i] == '_')
			{
				i++;
				end++;
			}
			val = get_var_val(ft_strsub(buff, start, end), head);
			end = 0;
			while (val && val[end])
			{
				str[j] = val[end];
				end++;
				j++;
			}
		}
		else if (buff[i] == '~')
		{
			i++;
			val = get_var_val("HOME", head);
			end = 0;
			while (val && val[end])
			{
				str[j] = val[end];
				end++;
				j++;
			}
		}
		else
		{
			str[j] = buff[i];
			i++;
			j++;
		}
	}
	return (str);
}
