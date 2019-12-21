/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:53:11 by sazouaka          #+#    #+#             */
/*   Updated: 2018/11/10 09:45:51 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	a = (char *)malloc(size * sizeof(char) + 1);
	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
		a[i++] = 0;
	a[i] = '\0';
	return (a);
}
