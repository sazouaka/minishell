/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 13:48:40 by sazouaka          #+#    #+#             */
/*   Updated: 2018/11/10 09:55:04 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_next_line(const int fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	char				*str;
	char				*tmp;
	int					i;

	str = NULL;
	if (fd < 0 || read(fd, buff, 0) < 0 || line == NULL)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		buff[i] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
	}
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	*line = ft_strsub(str, 0, i);
	free(str);
	return (1);
}
