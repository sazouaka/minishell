/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:51:06 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/21 18:51:08 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_parse_len(char *buff, t_lst *head)
{
	int		i;
	int		j;
	int		end;
	int		len;
	char	*val;

	i = 0;
	j = 0;
	len = 0;
	while (buff[i])
	{
		if (buff[i] && (buff[i] == ' ' || buff[i] == '\t'))
		{
			len++;
			j++;
			i++;
		}
		else if (buff[i] == 39)
		{
			i++;
			while (buff[i] && buff[i] != 39)
			{
				len++;
				j++;
				i++;
			}
			i++;
		}
		else if (buff[i] == 34)
		{
			i++;
			while (buff[i] && buff[i] != 34)
			{
				if (buff[i] == '$' && (ft_isalnum(buff[i + 1])
				|| buff[i + 1] == '_'))
				{
					i++;
					val = get_var_val(&buff[i], &end, head);
					i = i + end;
					end = 0;
					while (val[end])
					{
						len++;
						end++;
						j++;
					}
				}
				else
				{
					len++;
					j++;
					i++;
				}
			}
			i++;
		}
		else if (buff[i] == '$' && (ft_isalnum(buff[i + 1])
		|| buff[i + 1] == '_'))
		{
			i++;
			val = get_var_val(&buff[i], &end, head);
			i = i + end;
			end = 0;
			while (val && val[end])
			{
				len++;
				end++;
				j++;
			}
		}
		else if (buff[i] == '~' && ((buff[i - 1] == ' ' || i == 0)
		&& (buff[i + 1] == ' ' || buff[i + 1] == '/'
		|| buff[i + 1] == '\0')))
		{
			i++;
			val = get_var_val("HOME", &end, head);
			end = 0;
			while (val && val[end])
			{
				len++;
				end++;
				j++;
			}
		}
		else
		{
			len++;
			i++;
			j++;
		}
	}
	return (len);
}
