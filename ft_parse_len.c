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

void	single_q_len(char *buff, int *len, int *i)
{
	(*i)++;
	while (buff[*i] && buff[*i] != 39)
	{
		(*len)++;
		(*i)++;
	}
	(*i)++;
}

void	dolar_len(char *buff, int *len, int *i, t_lst *head)
{
	int		end;
	char	*val;

	(*i)++;
	val = get_var_val(&buff[*i], &end, head);
	*i = *i + end;
	end = 0;
	while (val && val[end])
	{
		(*len)++;
		end++;
	}
}

void	double_q_len(char *buff, int *len, int *i, t_lst *head)
{
	(*i)++;
	while (buff[*i] && buff[*i] != 34)
	{
		if (buff[*i] == '$' && NEXT_CHAR(buff[*i + 1]))
			dolar_len(buff, len, i, head);
		else
		{
			(*len)++;
			(*i)++;
		}
	}
	(*i)++;
}

void	tilde_len(int *len, int *i, t_lst *head)
{
	int		end;
	char	*val;

	(*i)++;
	val = get_var_val("HOME", &end, head);
	end = 0;
	while (val && val[end])
	{
		(*len)++;
		end++;
	}
}

int		ft_parse_len(char *buff, t_lst *head)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (buff[i])
	{
		if (buff[i] && (buff[i] == ' ' || buff[i] == '\t'))
			ft_len(&i, &len);
		else if (buff[i] == 39)
			single_q_len(buff, &len, &i);
		else if (buff[i] == 34)
			double_q_len(buff, &len, &i, head);
		else if (buff[i] == '$' && NEXT_CHAR(buff[i + 1]))
			dolar_len(buff, &len, &i, head);
		else if (buff[i] == '~' && ((buff[i - 1] == ' ' || i == 0)
		&& (buff[i + 1] == ' ' || buff[i + 1] == '/'
		|| buff[i + 1] == '\0')))
			tilde_len(&len, &i, head);
		else
			ft_len(&i, &len);
	}
	return (len);
}
