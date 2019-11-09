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
	static char			*str;
	char				*tmp;
	int					ret;
	int					i;

	i = 0;
	if (fd < 0 || read(fd, buff, 0) < 0 || line == NULL)
		return (-1);
	if (str == NULL)
		str = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (ft_strlen(str) == 0 && ret == 0)
	{
		free(str);
		return (0);
	}
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	*line = ft_strsub(str, 0, i);
	tmp = ft_strdup(str + i + 1);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (1);
}
