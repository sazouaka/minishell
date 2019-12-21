/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:05:24 by sazouaka          #+#    #+#             */
/*   Updated: 2018/11/07 15:45:41 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
