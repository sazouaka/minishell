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

void	replace_space(char *str, t_point *ps)
{
	str[ps->j] = 31;
	(ps->j)++;
	(ps->i)++;
}

void	ft_tilde(char *str, t_lst *head, t_point *ps)
{
	char	*val;
	int		end;

	ps->i++;
	val = get_var_val("HOME", &end, head);
	end = 0;
	while (val && val[end])
	{
		str[ps->j] = val[end];
		end++;
		ps->j++;
	}
}

int		empty_flag(char *str, int j)
{
	str[j] = '\0';
	if (j == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*ft_parse(char *buff, t_lst *head)
{
	t_point ps;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_parse_len(buff, head) + 1));
	ps = (t_point){0, 0};
	while (buff[ps.i])
	{
		if (buff[ps.i] == 39 && single_quote_1(buff, str, &ps))
			return (ft_strnew(0));
		else if (buff[ps.i] == 34 && double_quote_1(buff, str, head, &ps))
			return (ft_strnew(0));
		else if (buff[ps.i] && (buff[ps.i] == ' ' || buff[ps.i] == '\t'))
			replace_space(str, &ps);
		else if (buff[ps.i] == '$' && NEXT_CHAR(buff[ps.i + 1]))
			ft_dolar(buff, str, head, &ps);
		else if (buff[ps.i] == '~' && ((buff[ps.i - 1] == ' ' || ps.i == 0)
		&& (buff[ps.i + 1] == ' ' || buff[ps.i + 1] == '/'
		|| buff[ps.i + 1] == '\0')))
			ft_tilde(str, head, &ps);
		else if (BUFF_CHAR(buff[ps.i]))
			get_str(buff, str, &ps);
	}
	if (empty_flag(str, ps.j))
		return (NULL);
	return (str);
}
