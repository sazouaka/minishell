/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 01:13:58 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/21 01:14:16 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		verify_type(char *file)
{
	struct  stat    st;
	int             ret;
	DIR				*dir;

	if ((ret = lstat(file, &st)) == 0)
	{
		if (S_ISDIR(st.st_mode))
			return (1);
		if (S_ISLNK(st.st_mode))
		{
			if ((dir = opendir(file)) != NULL)
			{
				closedir(dir);
				return (1);
			}
			else
				return (2);
		}
		else
			return (2);
	}
	if (ret == -1)
		return (-1);
	return (0);
}
