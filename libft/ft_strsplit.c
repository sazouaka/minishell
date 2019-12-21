/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:19:10 by sazouaka          #+#    #+#             */
/*   Updated: 2018/10/21 15:40:23 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countword(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

static	int	ft_wordlen(char const *s, char c)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	count;
	char	**tab;

	if (str == NULL)
		return (NULL);
	count = ft_countword(str, c);
	if (!(tab = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (count--)
	{
		while (*str == c && *str != '\0')
			str++;
		tab[i] = ft_strsub(str, 0, ft_wordlen(str, c));
		if (tab[i] == 0)
			return (0);
		str = str + ft_wordlen(str, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
