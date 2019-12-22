/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_dolar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 20:23:11 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/22 20:23:14 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		single_quote_1(char *buff, char *str, t_point *ps)
{
	ps->i++;
	while (buff[ps->i] && buff[ps->i] != 39)
	{
		str[ps->j] = buff[ps->i];
		ps->j++;
		ps->i++;
	}
	if (buff[ps->i] != 39)
	{
		ft_putstr("Unmatched '.\n");
		free(str);
		return (1);
	}
	ps->i++;
	return (0);
}

void	ft_dolar(char *buff, char *str, t_lst *head, t_point *ps)
{
	char	*val;
	int		end;

	ps->i++;
	val = get_var_val(&buff[ps->i], &end, head);
	ps->i = ps->i + end;
	end = 0;
	while (val && val[end])
	{
		str[ps->j] = val[end];
		end++;
		ps->j++;
	}
}

void	get_str(char *buff, char *str, t_point *ps)
{
	str[ps->j] = buff[ps->i];
	ps->j++;
	ps->i++;
}

int		double_quote_2(char *str)
{
	ft_putstr("Unmatched \".\n");
	free(str);
	return (1);
}

int		double_quote_1(char *buff, char *str, t_lst *head, t_point *ps)
{
	ps->i++;
	while (buff[ps->i] && buff[ps->i] != 34)
	{
		if (buff[ps->i] == '$' && NEXT_CHAR(buff[ps->i + 1]))
			ft_dolar(buff, str, head, ps);
		else
			get_str(buff, str, ps);
	}
	if (buff[ps->i] != 34)
		return (double_quote_2(str));
	ps->i++;
	return (0);
}
