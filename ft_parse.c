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

char *ft_parse(char *flag, t_lst *head)
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
	while (flag[i])
	{
		// if ((flag[i] == 34 && flag[i + 1] == 34) || (flag[i] == 39 && flag[i + 1] == 39))
		// {
		// 	str[j] = ' ';
		// 	j++;
		// 	i = i + 1;
		// }
		if (flag[i] && (flag[i] == ' ' || flag[i] == '\t'))
		{
			str[j] = 31;
			j++;
			i++;
		}
		else if (flag[i] == 39)
		{
			i++;
			while (flag[i] && flag[i] != 39)
			{
				str[j] = flag[i];
				j++;
				i++;
			}
			i++;
		}
		else if (flag[i] == 34)
		{
			i++;
			if (flag[i] == '$')
			{
				i++;
				start = i;
				end = 0;
				while (isalnum(flag[i]) || flag[i] == '_')
				{
					i++;
					end++;
				}
				val = get_var_val(ft_strsub(flag, start, end), head);
				end = 0;
				while (val[end])
				{
					str[j] = val[end];
					end++;
					j++;
				}
			}
			while (flag[i] && flag[i] != 34)
			{
				str[j] = flag[i];
				j++;
				i++;
			}
			i++;
		}
		else if (flag[i] == '$')
		{
			i++;
			start = i;
			end = 0;
			while (isalnum(flag[i]) || flag[i] == '_')
			{
				i++;
				end++;
			}
			val = get_var_val(ft_strsub(flag, start, end), head);
			end = 0;
			while (val && val[end])
			{
				str[j] = val[end];
				end++;
				j++;
			}
		}
		else if (flag[i] == '~')
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
			str[j] = flag[i];
			i++;
			j++;
		}
	}
	return (str);
}
